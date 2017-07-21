An attempt to Implement Viola Jones face detector:

Reference:
[1] Viola P, Jones M J. Robust Real-Time Face Detection[J]. International Journal of Computer Vision, 2004, 57(2):137-154.

[2] Wang Y Q. An Analysis of the Viola-Jones Face Detection Algorithm[J]. Image Processing on Line, 2014, 4:128-148.

[3] Pham M T, Chain T J. Fast training and selection of Haar features using statistics in boosting-based face detection[C]// IEEE, International Conference on Computer Vision. IEEE, 2007:1-7.

Environment:
VS2010

Language:
C++

Files:
./results/...vj: text file, record the model trained.

./results/...jpg: coarse result

./boostFace/boostFace/

Global.h: headers and macros

Classifier .h, .cpp: weak classifer

Element .h, .cpp: single sample

Feature .h, .cpp: haar features

Gaussian .h: fast Gaussian probability calculation

Sample .h, .cpp: samples for training

VJdetector .h, .cpp: core class, process manager

mainpre.cpp: preprocessing

main.cpp: entrance


