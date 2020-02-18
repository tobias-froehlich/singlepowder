#ifndef DIFFRACTOGRAM_H_
#define DIFFRACTOGRAM_H_

class Diffractogram {
  private:
    int zLength = 0;
    float zAngleMin;
    float zAngleMax;
    float zStep;
    std::string zOutputFormat = "";
    std::vector< float > zAngles{};
    std::vector< int > zNumOfPixels{};
    std::vector< float > zSumOfWeights{};
    std::vector< float > zSumOfWeightedCounts{};
    std::vector< float > zSumOfSquareweightedCounts{};
    std::vector< float > zIntensities{};
    std::vector< float > zErrors{};
  public:
    Diffractogram();
    ~Diffractogram();
    void init(float angle_min, float angle_max, float step);
    void set_output_format(std::string output_format);
    int get_length();
    float get_angle_min();
    float get_angle_max();
    float get_step();
    float get_angle(int index);
    int get_num_of_pixels(int index);
    float get_sum_of_weights(int index);
    float get_sum_of_weighted_counts(int index);
    float get_sum_of_squareweighted_counts(int index);
    float get_intensity(int index);
    float get_error(int index);
    void add_counts(float angle, int counts, float weight);
    void calculate_intensities_and_errors();
    void write_file(std::string filename);
};

#endif
