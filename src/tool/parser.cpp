#include "tool/parser.hpp"

std::vector<Characteristic> parseCharacteristics(const char* docname){
    std::vector<Characteristic> listCharacteristics ;
    // Create empty XML document within memory
    pugi::xml_document doc;
    // Load XML file into memory
    // Remark: to fully read declaration entries you have to specify
    // "pugi::parse_declaration"
    pugi::xml_parse_result result = doc.load_file(docname,
        pugi::parse_default|pugi::parse_declaration);
    if (!result)
    {
        std::cout << "Parse error: " << result.description()
            << ", character pos= " << result.offset;
    }
    // A valid XML document must have a single root node
    pugi::xml_node root = doc.document_element();


    for (pugi::xml_node_iterator it = root.begin(); it != root.end(); ++it){
        int id = atoi(it->attribute("id").value());
        int vmin = atoi(it->child("min").child_value());
        int vmax = atoi(it->child("max").child_value());
        int precision = atoi(it->child("precision").child_value());

        listCharacteristics.push_back(Characteristic(id,vmin,vmax,it->child("name").child_value(),it->child("definition").child_value(),precision));
    }
    return listCharacteristics;
}
