#ifndef LIST_H_
#define LIST_H_

class List {
  private:
    std::string zDataDirectory = "";
    std::vector<Action*> zActions{};
    int zLength = 0;
  public:
    List();
    ~List();
    void set_datadirectory(std::string datadirectory);
    std::string get_datadirectory();
    void read_file(std::string filename);
    int get_length();
    std::vector<Action*> get_actions();
};

#endif
