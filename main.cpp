#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "kche.h"
#include "ring_list.h"
using namespace std;

vector<string> split(string line, char delimiter) {
    string part;
    stringstream ss(line);

    vector<string> v;
    while (getline(ss, part, ' ')) {

        v.push_back(part);
    }
    return v;

}


KeyType to_key(string line) {
    vector<string> value_vector = split(line, ' ');
    KeyType new_key = {stoi(value_vector[0]), stoi(value_vector[1])};
    return new_key;
}

bool is_number(string str) {
    bool flag = true;
    for (int i = 0; i < str.length(); i++) {
        if (!isdigit(str[i])) {
            flag = false;
        }
    }
    return flag;
}

bool file_is_valid(string filename) {
    ifstream file;
    file.open(filename);
    string line;
    bool is_valid = true;
    while (getline(file, line)) {
        vector<string> line_vector = split(line, ' ');
        if (line_vector.size() != 2) {
            is_valid = false;
        }
        if (line_vector.size() == 2) {
            if (!(is_number(line_vector[0]) && is_number(line_vector[1]))) {
                is_valid = false;
            }
        }
        if (line_vector.size() == 2) {
            if (is_number(line_vector[0]) && is_number(line_vector[1])) {
                if ((line_vector[0].length() != 4) || (line_vector[1].length() != 6)) {
                    is_valid = false;
                }
            }
        }
    }
    file.close();
    return is_valid;
}

void get_tree_vector(Node*& root, vector<KeyType>& vect) {
    if (root != nill && root != nullptr) {
        get_tree_vector(root->LeftChild, vect);
        Elem* pointer = root->DuplicationList;
        if (pointer != nullptr) {
            do {
                vect.push_back(root->key);
                pointer = pointer->next;
            } while (pointer != root->DuplicationList);
        }
        get_tree_vector(root->RightChild, vect);
    }
}

void print_in_file(Node* root, string filename) {
    ofstream file;
    file.open(filename);
    vector<KeyType> vect;

    if (root != nullptr) {
        get_tree_vector(root, vect);
        for (int i = 0; i < vect.size(); i++) {
            file << vect[i].series << ' ' << vect[i].number << '\n';
        }
    }
    file.close();
}


int main() {
    string DATA_FILE = "data.txt";
    string RESULT_FILE = "result.txt";
    bool is_valid = file_is_valid(DATA_FILE);

    if (is_valid) {

        ifstream fin;
        fin.open(DATA_FILE);
        std::string line;
        int string_num = 0;

        Node* root_node = init();
        KeyType root_key;

        while (getline(fin, line)) {
            string_num += 1;
            KeyType current_key = to_key(line);
            cout << current_key.series << ' ' << current_key.number << endl;
            if (string_num == 24) {
                root_node = insert_in_tree(root_node, current_key, string_num);
            } else if (string_num == 27) {
                root_node = insert_in_tree(root_node, current_key, string_num);
            } else {
                root_node = insert_in_tree(root_node, current_key, string_num);
            }
        }

        //straight_write(root_node, 50);
        KeyType rem_key = {1000, 300000};
        root_node = delete_in_tree(root_node, rem_key, 24);
        straight_write(root_node, 50);
        root_node = delete_in_tree(root_node, rem_key, 27);
        root_node = delete_in_tree(root_node, rem_key, 7);
        root_node = delete_in_tree(root_node, rem_key, 2);
        //straight_write(root_node, 50);
        print_in_file(root_node, RESULT_FILE);
        fin.close();

        // Node* root = init();
        // KeyType m1;
        // for (int i = 10; i < 15; ++i) {
        //     m1 = {i*100, i*10000};
        //     root = insert_in_tree(root, m1, i);
        // }
        // bypass(root);
        // straight_write(root, 30);

   } else {
    cout << "Неверный формат данных" << endl;
   }

};