#include "XMLParser.h"



int XMLParser::loadXMLDocument(XMLDocument* doc, const char* path, XMLNodeList* list) {
// int XMLParser2::loadXMLDocument(const char* path) {
    // XMLDocument document;
    // XMLNodeList temp_list;
    if(!SPIFFS.begin(true)){
        Serial.println("An Error has occurred while mounting SPIFFS");
        return 0;
    }
    // Test here --> Opens
    fs::File filep = SPIFFS.open("/Machine.xml", "r");
    if (!filep) {
        Serial.println("Failed to open file");
        return 0;
    }

    size_t filesize = filep.size();
    // Serial.println("File size: " + String(filesize));
    char* buffer = (char*) malloc(sizeof(char) * filesize + 1);

    // Problem when the size is 629 or 630

    //
    // Variables
    //
    char c;
    int d = 0;
    int tagBool = FALSE;
    int tagContent = FALSE;
    int size = 1;

    // Node variables
    char wordu[256];
    char type[3][20] = {
        "attribute",
        "key",
        "value"
    };
    int degree=0;

    doc->root = XMLNode_init();
    XMLNode* current_node = doc->root;
    XMLNodeList* node_list = list;
    XMLNodeList_init(node_list);

    size = 1;
    // Serial.println("Oui je teste");
    while (filep.available()) {
        // Serial.print("Size: "); Serial.println(size);
        c = filep.read();

        // Booleans to know if we are in a tag
        // and cut or not the content
        if(tagContent && c == '\n') {
            tagContent = FALSE;
        }
        // Don't know the whole structure of XML but here when it comes back to the line
        // we empty the buffer. Possibility to optimize here [TODO]
        if (c == '\n' && d > 0) {
            for (int i = 0; i < d + 1; i++)
                buffer[i] = 0;
            d=0;
        }

        //Recognize end of tag
        if (c == '>') {

            if (tagBool) {
                // This is where we catch the end of a tag, need to be carefull with the index of the 
                // tag. As we said, ftell starts with 1, not 0
                current_node->end = size;
                // Here we check if we are in the beginning of a tag
                // [TODO] --> To implement a way to define attributes here
                // Not implemented on purpose
                if (!starts_with(buffer, '/')) {
                    // Increase the degree (the depth of the tag)
                    degree++;
                    // Copy the content of the buffer inside the word
                    for (int i = 0; i < d + 1; i++) {
                        wordu[i] = buffer[i];
                    }
                    // Add the new node
                    // strdup --> function to create a kind of new pointer automatically
                    current_node->word = strdup(wordu);
                    current_node->type = strdup(type[1]);
                    current_node->degree = degree;
                    // Add it to the list
                    XMLNodeList_add(node_list, current_node);
                }

                // Decrease the degree if we encounter a closing tag
                if (starts_with(buffer, '/')) {
                    degree--;
                }
                // Reset the buffer
                for (int i = 0; i < d + 1; i++)
                    buffer[i] = 0;
                d=0;
            }

            // Reset the booleans
            tagBool = FALSE;
            tagContent = TRUE;
            current_node->start = size;
        }

        // Copies tag in buffer
        if(tagBool && c!= '>' && c != '<') {
            buffer[d] = c;
            buffer[d+1] = '\0';
            d++;
        }

        // Copies content in buffer
        // Consider that the buffer is smaller than 256 char
        if(tagContent && c!= '>' && c != '<') {
            buffer[d] = c;
            buffer[d+1] = '\0';
            d++;
        }

        // Recognize beginning of tag
        if (c == '<') {
            // printf("Position beginning: %ld\n", ftell(file));
            // We get the start position of any node here, the position starts with 1
            // but in ftell terms it's the 0. However, we'll have to add 1
            if (tagContent)
                current_node->end = size;
            else 
                current_node->start = size;
            if(tagContent) {
                for (int i = 0; i < d + 1; i++) {
                    wordu[i] = buffer[i];
                }
                current_node->word = strdup(wordu);
                current_node->type = strdup(type[2]);
                current_node->degree = degree;
                // if (!strcmp(getLast(node_list),"test"))
                //     printf("Position: %ld\n", ftell(file));
                XMLNodeList_add(node_list, current_node);
                for (int i = 0; i < d + 1; i++)
                    buffer[i] = 0;
                d=0;
                
            }

            // Reset the booleans
            tagContent = FALSE;
            tagBool = TRUE;
        }
        size++;
    }
    
    filep.close();
    free(buffer);
    free(current_node);
    // free(node_list);
    return 1;
}


// Check if the string starts with a specific character 
int XMLParser::starts_with(const char *str, const char ch ){
    return str[0] == ch;
}

// Instantiate a new node using a parent node
XMLNode* XMLParser::XMLNode_new(XMLNode* parent) {
    XMLNode* node = (XMLNode*)malloc(sizeof(XMLNode));;
    node->word = parent->word;
    node->type = parent->type;
    node->degree = parent->degree;
    node->start = parent->start;
    node->end = parent->end;
    return node;
}

// Free the node
void XMLParser::XMLNode_free(XMLNode* node) {
    if (node->word != NULL) {
        free(node->word);
    }
    if (node->type != NULL) {
        free(node->type);
    }
    node->degree = 0;
    node->start = 0;
    node->end = 0;
    // free(node);
};

// Initialize a new Node
XMLNode* XMLParser::XMLNode_init() {
    XMLNode* node = (XMLNode*)malloc(sizeof(XMLNode));;
    node->word = NULL;
    node->type = NULL;
    node->degree = 0;
    node->start = 0;
    node->end = 0;
    return node;
}

// Initialize the list of nodes
void XMLParser::XMLNodeList_init(XMLNodeList* list)
{
    list->heap_size = 1;
    list->size = 0;
    list->data = (XMLNode**) malloc(sizeof(XMLNode*) * list->heap_size);
}

// Add a new node
void XMLParser::XMLNodeList_add(XMLNodeList* list, XMLNode* node)
{
    while (list->size >= list->heap_size) {
        list->heap_size *= 2;
        list->data = (XMLNode**) realloc(list->data, sizeof(XMLNode*) * list->heap_size);
    }
    list->data[list->size++] = XMLNode_new(node);
}

// Print the list of nodes
void XMLParser::XMLNodeList_print(XMLNodeList* list) {
    for (int i = 0; i < list->size; i++) {
        printf("Word : %s, Type: %s, Degree: %d, Start: %ld, End: %ld\n", 
        list->data[i]->word, list->data[i]->type, list->data[i]->degree,
        list->data[i]->start, list->data[i]->end);
    }
}

// Free the list of Nodes
void XMLParser::XMLNodeList_free(XMLNodeList* list)
{
    if (list->data != NULL) {
        for (int i = 0; i < list->size; i++) {
            XMLNode_free(list->data[i]);
        }
        free(list->data);
    }
    list->data = NULL;
    list->heap_size = 0;
    list->size = 0;
    // free(list);
}

// Get the content the word of Node
// [TODO] --> Rename it because it feels like we get the content of the next node
// So it would be better with a "Get content node"
char* XMLParser::XMLNode_getWord(XMLNodeList* list,  const char* node) {
    XMLNode* current;
    for (int i = 0; i < list->size; i++) {
        current = list->data[i];
        if (strcmp(current->word, node) == 0) {
            if (i+1 < list->size)
                if (strcmp(list->data[i+1]->word, "") == 0)
                    return NULL;
                return list->data[i+1]->word;
            return NULL;
        }
    }
    return NULL;
}

// Get the type of the node
char* XMLParser::XMLNode_getType(XMLNodeList* list,  char* node) {
    XMLNode* current;
    for (int i = 0; i < list->size; i++) {
        current = list->data[i];
        if (strcmp(current->word, node) == 0) {
            if (i+1 < list->size)
                return list->data[i+1]->type;
            return NULL;
        }
    }
    return NULL;
}

// Get the degree of the node
int XMLParser::XMLNode_getDegree(XMLNodeList* list,  char* node) {
    XMLNode* current;
    for (int i = 0; i < list->size; i++) {
        current = list->data[i];
        if (strcmp(current->word, node) == 0) {
            if (i+1 < list->size)
                return list->data[i+1]->degree;
            return -1;
        }
    }
    return -1;
}

// Get the start of the node
long int XMLParser::XMLNode_getStart(XMLNodeList* list,  char* node) {
    XMLNode* current;
    for (int i = 0; i < list->size; i++) {
        current = list->data[i];
        if (strcmp(current->word, node) == 0) {
            return list->data[i]->start;
        }
    }
    return -1;
}

// Get the end of the node
long int XMLParser::XMLNode_getEnd(XMLNodeList* list, char* node) {
    XMLNode* current;
    for (int i = 0; i < list->size; i++) {
        current = list->data[i];
        if (strcmp(current->word, node) == 0) {
            return list->data[i]->end;

        }
    }
    return -1;
}

// Get the previous node
// [TODO] --> Test this function because it seems as if it gives the normal amount of node
char* XMLParser::XMLNode_getNode(XMLNodeList* list,  char* text) {
    XMLNode* current;
    for (int i = 0; i < list->size; i++) {
        current = list->data[i];
        if (strcmp(current->word, text) == 0) {
            if (i > 0)
                return list->data[i-1]->word;
            return NULL;
        }
    }
    return NULL;
}

// Get Last Node
char* XMLParser::getLast(XMLNodeList* list) {
    if (list->size != 0) {
        // printf("Get Last test %s\n", list->data[list->size-1]->word);
        return list->data[list->size-1]->word;
    }
    return NULL;
}

XMLNode * XMLParser::getNodeContent(XMLNodeList * list, const char* node) {

    XMLNode* current;
    for (int i = 0; i < list->size; i++) {
        current = list->data[i];
        if (strcmp(current->word, node) == 0) {
            if (i+1 < list->size)
                return list->data[i+1];
            return NULL;
        }
    }
    return NULL;
}

int XMLParser::reloadXMLDocument(XMLDocument* doc, const char* path, XMLNodeList* list) {
    XMLNodeList_free(list);
    XMLNodeList_init(list);
    return loadXMLDocument(doc, path, list);
}

// It works as well when the field is empty

int XMLParser::replaceXMLtext(const char * file_name, const char * insertion, XMLNode * node) {

    // Open the file and get the size of it
    if(!SPIFFS.begin(true)){
        Serial.println("An Error has occurred while mounting SPIFFS");
        return 0;
    }
    // Test here --> Opens
    fs::File filep = SPIFFS.open("/Machine.xml", "r");
    if (!filep) {
        Serial.println("Failed to open file");
        return 0;
    }

    size_t filesize = filep.size();
    // Serial.println("File size: " + String(filesize));
    char* buffer = (char*) malloc(sizeof(char) * filesize + 1);


    // Store the values in the buffer
    for (int i = 0; i < filesize; i++) {
        buffer[i] = filep.read();
    }
    buffer[filesize] = '\0';

    // Get the length of the insertion
    size_t length = strlen(insertion);

    // [TODO] --> Make the insertion operation here (So take out a word and replace it for instance)
    // Maybe in the future we'll need a XMLNode to access directly the start and the end
    int start = node->start;
    int end = node->end - 1;

    // Here what we will do is to take the size of the buffer, substract the (end - start)
    // and then add the length of the word. --> this will give the new size of the buffer
    int final_size = filesize - (end - start) + length + 1;
    char * buffer_fsize = (char*) malloc(sizeof(char) * final_size);

    // Implement the first loop up to the index 
    for (int i = 0; i < start; i++) {
        buffer_fsize[i] = buffer[i];
    }
    // Implement the second loop for the replacing word
    // from the start index to the length of the new word
    for (int i = start; i < start + length; i++) {
        buffer_fsize[i] = insertion[i-start];
    }
    // implement the rest of the document
    // from the end index to the end of the buffer 1
    for(int i = end; i < filesize; i++) {
        buffer_fsize[start + length + (i-end)] = buffer[i];
    }

    buffer_fsize[final_size] = '\0';
    // printf("%s\n", buffer_fsize);
    // printf("*************************\n");
    
    filep.close();

    filep = SPIFFS.open("/Machine.xml", FILE_WRITE);
    if(!filep) {
        Serial.println("Failed to open file");
        return 0;
    }
    size_t bytesWritten = filep.write((const uint8_t*)buffer_fsize, strlen(buffer_fsize));
    if (bytesWritten == strlen(buffer_fsize)) {
        Serial.println("File written successfully");
    } else {
        Serial.println("Failed to write complete buffer to file");
    }
    filep.close();

    free(buffer);
    free(buffer_fsize);
    return 1;
}