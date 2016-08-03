#ifndef KMEANS_H_
#define KMEANS_H_


#include <iostream>
//#include <offload.h>
#include <Eigen/Dense>
#include "utils.hpp"

#define ALLOC alloc_if(1) free_if(0)
#define FREE alloc_if(0) free_if(1)
#define REUSE alloc_if(0) free_if(0)

using namespace Eigen;

class kmeans
{
public:
    kmeans();
    void cluster(const MatrixXd &points, MatrixXd &centroids);
    void e_step(const MatrixXd &points, MatrixXd &centroids);
    void m_step(const MatrixXd &points, MatrixXd &centroids);
    int find_nearest_centroid(const RowVectorXd &point, MatrixXd &centroids);
    double euclid_distance(const VectorXd& A, const VectorXd& B);
private:
    Utils utils;
    int padding;
    int alignment;
};

#endif // KMEANS_H_
