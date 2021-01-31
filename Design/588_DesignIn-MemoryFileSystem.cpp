class File {
    
private:
    
    string content;
    
public:
    
    File() : content("") {}
    
    void addContent(const string& newContent) {
        content += newContent;
    }
    
    string getContent() {
        return content;
    }
    
};


class Directory {
    
 private:
    
    unordered_map<string, Directory*> innerDirs;
    
    unordered_map<string, File*> innerFiles;
    
    vector<string> lexOrder;
    
public:
    
    ~Directory() {
        
        for(auto& i : innerDirs) {
            delete i.second;
        }
        
        for(auto& i : innerFiles) {
            delete i.second;
        }
        
    }
    
    vector<string> ls(const string& path, int curIndex) {
        
        if(curIndex >= path.length()) {
            sort(lexOrder.begin(), lexOrder.end());
            return lexOrder;
        }
        
        int highIndex = getEndIndex(path, curIndex);
        string nextDocument = path.substr(curIndex, highIndex - curIndex + 1);
        
        if(innerDirs.find(nextDocument) != innerDirs.end()) {
            return innerDirs[nextDocument]->ls(path, highIndex + 2);
        }
        
        return {nextDocument};
    }
    
    void mkdir(const string& path, int curIndex) {
        
        if(curIndex >= path.length()) {
            return;
        }
        
        int highIndex = getEndIndex(path, curIndex);
        string nextDocument = path.substr(curIndex, highIndex - curIndex + 1);
        
        if(innerDirs.find(nextDocument) == innerDirs.end()) {
            lexOrder.push_back(nextDocument);
            innerDirs[nextDocument] = new Directory();
        }
        
        innerDirs[nextDocument]->mkdir(path, highIndex + 2);
    }
    
    void addContent(const string& content, const string& path, int curIndex) {
        
        int highIndex = getEndIndex(path, curIndex);
        string nextDocument = path.substr(curIndex, highIndex - curIndex + 1);
        
        if(highIndex == path.length() - 1) {
            
            if(innerFiles.find(nextDocument) == innerFiles.end()) {
                lexOrder.push_back(nextDocument);
                innerFiles[nextDocument] = new File();
            }
            
            innerFiles[nextDocument]->addContent(content);
        } else {
            innerDirs[nextDocument]->addContent(content, path, highIndex + 2);
        }
        
    }
    
    string getContent(const string& path, int curIndex) {
        
        int highIndex = getEndIndex(path, curIndex);
        string nextDocument = path.substr(curIndex, highIndex - curIndex + 1);
        
        if(highIndex == path.length() - 1) {
            return innerFiles[nextDocument]->getContent();
        }
        
        return innerDirs[nextDocument]->getContent(path, highIndex + 2);
    }
    
    
private:
    
    int getEndIndex(const string& path, int curIndex) {
        
        int highIndex = curIndex + 1;
        
        while(highIndex < path.length() && path[highIndex] != '/') {
            ++highIndex;
        }
        
        return highIndex - 1;
    }
    
};



class FileSystem {
    
private:
    
    Directory* base;
    
public:
    FileSystem() : base(new Directory) {}
    
    ~FileSystem() {
        delete base;
    }
    
    vector<string> ls(string path) {
        return base->ls(path, 1);
    }
    
    void mkdir(string path) {
        base->mkdir(path, 1);
    }
    
    void addContentToFile(string filePath, string content) {
        base->addContent(content, filePath, 1);
    }
    
    string readContentFromFile(string filePath) {
        return base->getContent(filePath, 1);
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
