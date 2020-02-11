#ifndef ACTION_H_
#define ACTION_H_

class Action {
  private:
    std::string zDataFilename = "";
    float zTwotheta = 0;
    float zTheta = 0;
    float zChi = 0;
    float zDetectordistance = 0;
    float zScantime = 0;
    std::string zDataDirectory = "";
    DetectorImage* zDetectorImage;
  public:
    Action();
    ~Action();
    void read_line(std::string line);
    std::string get_data_filename();
    float get_twotheta();
    float get_theta();
    float get_chi();
    float get_detectordistance();
    float get_scantime();
    void read_detectorimage();
    void set_datadirectory(std::string datadirectory);
    std::string get_datadirectory();
    DetectorImage* get_detectorimage();
};

#endif
