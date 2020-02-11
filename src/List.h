#ifndef LIST_H_
#define LIST_H_

class List {
  private:
    std::string zDataDirectory;
    std::vector<Action*> zActions;
  public:
    List();
    ~List();
    void set_datadirectory(std::string datadirectory);
    std::string get_datadirectory();
    void read_file(std::string filename);
    std::vector<Action*> get_actions();
};

#endif
