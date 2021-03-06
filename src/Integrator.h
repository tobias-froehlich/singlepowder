#ifndef INTEGRATOR_H_
#define INTEGRATOR_H_

class Integrator {
  private:
    Parameters* zParameters;
    List* zList;
    Geometry* zGeometry;
    Diffractogram* zDiffractogram;
    Mask* zMask;
  public:
    Integrator();
    ~Integrator();
    void integrate(std::string parameterfilename);
};

#endif
