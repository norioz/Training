#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "attribute_parser.h"
#define END_NODE_TAG "END"

using namespace std;

struct Node {
    string tag = "UNSET";
    vector<string> attributes;
    vector<string> values;
};

// Creates a Node from a HRML line.
// Open element lines result in Nodes with appropriate tags
// and attributes.
// Close element lines result in Nodes with the tag "END" and
// empty attribute and element vectors.
Node line_to_node(string& s)
{
    Node result;

    // If the string starts with "</" then
    // create and end element Node.
    if (s[1] == '/') {
        result.tag = END_NODE_TAG;
        return result;
    }

    // Otherwise s represents the start of an element.
    stringstream ss(s);
    bool endFound = false;

    // process the tag
    string tmp_str = "UNSET";
    ss >> tmp_str;
    if (tmp_str[tmp_str.size() - 1] == '>') { // the element has no attributes
        endFound = true;                      // <tag>
        result.tag = tmp_str.substr(1, tmp_str.size() - 2);
    }
    else {
        result.tag = tmp_str.substr(1, tmp_str.size());
    }

    // process the attributes
    char tmp_char = '\0';
    while (!endFound) {
        ss >> tmp_str;
        if (tmp_str == ">") {  // Found a floating close angle brace.
            endFound = true;
            break;
        }
        result.attributes.push_back(tmp_str);
        ss >> tmp_char;  // drop the = in a attr = "val" statement
        ss >> tmp_str;
        if (tmp_str[tmp_str.size() - 1] == '>') {  // ends with the end open-element brace
            tmp_str = tmp_str.substr(1, tmp_str.size() - 3);  // prune the "">
            result.values.push_back(tmp_str);
            endFound = true;
        }
        else {
            tmp_str = tmp_str.substr(1, tmp_str.size() - 2);    // prune the "" off the value 
            result.values.push_back(tmp_str);
        }
    }
    return result;
}

int hackerrank::attribute_parser()
{
    // Process the line number descriptors.

    int n = -1, // the number of HRML lines
        q = -1; // the number of query lines
    string line = "UNSET";
    getline(cin, line);
    stringstream ss(line);
    ss >> n >> q;

    // Create nodes out of the HRML lines.
    vector<Node> nodes;
    vector<int> endIdxs;

    vector<int> startIdxStack;
    for (int i = 0; i < n; ++i) {
        getline(cin, line);
        Node n = line_to_node(line);
        nodes.push_back(n);
        endIdxs.push_back(-1);
        if (n.tag == END_NODE_TAG) {
            endIdxs[startIdxStack[startIdxStack.size() - 1]] = i;
            startIdxStack.pop_back();
        }
        else {
            startIdxStack.push_back(i);
        }
    }

    // Process the queries.
    for (int i = 0; i < q; ++i) {
        string query = "UNSET";
        getline(cin, query);
        
        string tagChain = "UNSET";
        string attribute = "UNSET";
        
        // Split the tag chain and target attribute apart.
        size_t pos = query.find("~");
        tagChain = query.substr(0, pos);
        attribute = query.substr(pos + 1, query.size());

        // Turn the tag chain into a vector of tags.
        vector<string> tags;
        stringstream ss(tagChain);
        string tag = "UNSET";
        while (getline(ss, tag, '.')) {
            tags.push_back(tag);
        }
        
        unsigned int nodeIdx = 0;
        int tagIdx = 0;
        while (nodeIdx < nodes.size()) {
            Node currentNode = nodes[nodeIdx];
            if (currentNode.tag == END_NODE_TAG) {   // A query can't step up levels so
                cout << "Not Found!" << endl; // finding an end node fails the query.
                break;
            }
            else if (currentNode.tag == tags[tagIdx]) {
                if ((tagIdx + 1) == tags.size()) {
                    unsigned int k = 0;
                    while (k < currentNode.attributes.size()) {
                        if (currentNode.attributes[k] == attribute) {
                            cout << currentNode.values[k] << endl;
                            break;
                        }
                        ++k;
                    }
                    if (k == currentNode.attributes.size()) {
                        cout << "Not Found!" << endl;
                    }
                    break;
                }
                else {
                    ++tagIdx;   // move to the next tag
                    ++nodeIdx;  // step into this node
                }
            }
            else {  // Move beyond the current element's end and try to match.
                nodeIdx = endIdxs[nodeIdx] + 1;
                if (nodeIdx == nodes.size()) {
                    cout << "Not Found!" << endl;
                }
            }
        }
    }

    return 0;
}
