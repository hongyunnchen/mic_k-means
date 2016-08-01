# Intel® Xeon Phi™ k-means

#### Description

This is an implementation of the k-means algorithm based on the [EM Algorithm](http://www.ics.uci.edu/~smyth/courses/cs274/notes/EMnotes.pdf), which uses the Intel® Xeon Phi™ Coprocessor via the Offload compute model to perform an asynchronous compute using the CPU and MIC. This implementation supports the use of multiple coprocessors. Aditionally it uses [Eigen 3](http://eigen.tuxfamily.org/) library to facilitate development, reading and understanding of the algorithm.
