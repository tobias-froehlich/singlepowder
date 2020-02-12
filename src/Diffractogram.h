#ifndef DIFFRACTOGRAM_H_
#define DIFFRACTOGRAM_H_

class Diffractogram {
  private:
    int zLength = 0;
    float zAngleMin;
    float zAngleMax;
    float zStep;
    std::vector< float > zAngles{};
    std::vector< int > zNumOfPixels{};
    std::vector< int > zCounts{};
  public:
    Diffractogram();
    ~Diffractogram();
    void init(float angle_min, float angle_max, float step);
    int get_length();
    float get_angle_min();
    float get_angle_max();
    float get_step();
    float get_angle(int index);
    int get_num_of_pixels(int index);
    int get_counts(int index);
    void add_counts(float angle, int counts);
};

#endif
