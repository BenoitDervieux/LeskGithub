# Learnings during the making of the project

## Fix guru exception
- Using this->XMLlist while the argument of the function was _XMLlist 
- Free some memory
- Use static for some functions/methods

## Mappings functions and class

- Need to write static for the methods (like static int getSettingsNumber(const char *name) )
- Write static for the mapping (like static SettingsMapping settings_mappings[] = )