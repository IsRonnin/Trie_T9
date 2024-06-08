#include "main.h"

using namespace std;


bool read_file(TrieNode* root, ifstream& file) {
    try {
        string line;
        
        while (getline(file, line))
        {
            for (auto& x : line) {
                x = tolower(x);
            }
            insert(root, line);
        }
        return true;
    }
    catch (...) {
        return false;
    }
}


int main()
{
    cout << "Start loading word's please wait..." << endl;
    char path[_MAX_PATH];
    GetModuleFileName(NULL, path, _MAX_PATH);
	string filename = "../../words.txt";
	ifstream fs(filename);

    if (!fs) {
        exit(-1);
    }

    TrieNode* root = new TrieNode();

    if (read_file(root, fs))
        cout << "Words succecfuly loaded, thank's for wating!" << endl;
    else {
        cout << "FAIL, please retry to load words - or update this application..." << endl;
        cout << "Please - Read file 'README.md' to repair prog" << endl;
        exit(404);
    }

    string word = "";
    cout << "To exit - write '0' - to work - write any english word or letter" << endl;
    while(true) {
        bool exist = true;
        string res;
        char* buf = new char[1024];
        cin >> word;    
        if (word == "0") exit(-1); 
        TrieNode* current = root;
        for (auto& c : word) {
            c = tolower(c);
            if(current->children[c - 'a'] != nullptr)
                current = current->children[c - 'a'];
            else {
                cout << "no word like this..." << endl;
                exist = false;
                break;
            }
        }
        if (exist) all_words(current,0,buf, res, word);
        else continue; 
        cout << res << endl;
    }

    fs.close();
	return 0;
}
