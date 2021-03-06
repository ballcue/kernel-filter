#ifndef KERNELFILTER_CPP
#define KERNELFILTER_CPP

#include "../include/KernelFilter.h"

template <typename DT, size_t CH>
KernelFilter<DT,CH>::KernelFilter(const Mat& image, const Mat& kernel, const Cell& kernelPin) :
    image(image), kernel(kernel), kernelPin(kernelPin) {}

template <typename DT, size_t CH>
KernelFilter<DT,CH>::KernelFilter(const Mat& image) : image(image) {}

template <typename DT, size_t CH>
void KernelFilter<DT,CH>::setKernel(Mat& kernel, Cell& kernelPin) {
    this->kernel = kernel;
    this->kernelPin = kernelPin;
}

template <typename DT, size_t CH>
Mat KernelFilter<DT,CH>::compute() const {
    // (no puedo armar el convolver cuando se construye el filter porque no se puede ejecutar un método abstrcto como toConvolutionData() en el constructor)
    Convolver convolver(toConvolutionData(), kernel, kernelPin);
    return convolver.convolveCroppingEdges();
}

#endif
