#ifndef XMLPARSER_H
#define XMLPARSER_H

// Disclaimer: I took a lot of inspiration from this person: https://github.com/jonahisadev/littlexml/blob/master/lxml.h
// I tried to follow his youtube tutorial first: https://www.youtube.com/watch?v=kPFYfTvMRs8&t=3898s

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "SPIFFS.h"

#ifndef TRUE
    #define TRUE 1
#endif
#ifndef FALSE
    #define FALSE 0
#endif

struct _XMLNode
{
    char* word;
    char* type;
    int degree;
    long start;
    long end;

};
typedef struct _XMLNode XMLNode;

struct _XMLDocument 
{
    XMLNode* root;
};
typedef struct _XMLDocument XMLDocument;

struct _XMLNodeList
{
    int heap_size;
    int size;
    struct _XMLNode** data;
};
typedef struct _XMLNodeList XMLNodeList;

class XMLParser {

public :
    // Functions declaration
    static int loadXMLDocument(XMLDocument* doc, const char* path, XMLNodeList* list);
    static int starts_with(const char *str, const char ch );
    static XMLNode* XMLNode_new(XMLNode* parent);
    static void XMLNode_free(XMLNode* node);
    static XMLNode* XMLNode_init();
    static void XMLNodeList_init(XMLNodeList* list);
    static void XMLNodeList_add(XMLNodeList* list, struct _XMLNode* node);
    static void XMLNodeList_print(XMLNodeList* list);
    static void XMLNodeList_free(XMLNodeList* list);
    static char* XMLNode_getWord(XMLNodeList* list,  const char* node);
    static char* XMLNode_getType(XMLNodeList* list,  char* node);
    static int XMLNode_getDegree(XMLNodeList* list,  char* node);
    static long int XMLNode_getStart(XMLNodeList* list,  char* node);
    static long int XMLNode_getEnd(XMLNodeList* list, char* node);
    static char* XMLNode_getNode(XMLNodeList* list,  char* text);
    static char* getLast(XMLNodeList* list);
    static XMLNode* getNodeContent(XMLNodeList * list, const char* node);
    static int reloadXMLDocument(XMLDocument* doc, const char* path, XMLNodeList* list);
    static int replaceXMLtext(const char * file_name, const char * insertion, XMLNode * node);
    void registerDocument(XMLDocument* doc);
    void registerList(XMLNodeList* _list);

public:
    XMLParser() {}
    XMLDocument doc;
    XMLNodeList list;

};



#endif