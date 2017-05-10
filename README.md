## MLsegment

#### Abstract

Visual surveillance requires the moving object to be captured and tracked. The basic technique used  
for discriminating moving objects from the static objects is background separation. Background  
separation will subtract the current frame from the reference frame of static objects. This method is  
not capable of handling multiple backgrounds like moving water in a fountain. Hence we have to  
use some other models like unimodal model, MOG, Kernel , CB, etc. for separating those variations.  

#### Team members
  &emsp;&emsp; 1401001 - Deep Parekh  
  &emsp;&emsp; 1401011 - Jeet Parekh   
  &emsp;&emsp; 1401035  - Krima Doshi  
  &emsp;&emsp; 1401061 - Maharshi Bhavsar  
 
#### Introduction 
Foreground-background segmentation is required when
motion of objects need to be detected. The moving objects
can be considered as foreground and the stationary objects
can be considered as background.
Next, we used MOG filter for the initial separation. Then
we took a reference frame and subtracted current frame from
the reference frame. This approach works for the stable camera
and a stable background and only a moving foreground.
For the moving background-foreground segmentation we
used a complex algorithm called Optical Flow.
Optical Flow is one of the tool at rescue to solve many
problems such as 3D shape acquisition, oculomotor control,
perceptual organization, object recognition and scene
understanding. Our problem statement is concerned with real
time video sequence in which objects(Human) or the camera
maybe moving according to 3D path. Optical flow provides
visual perception.

#### Optical Flow 
Optical flow is implemented by studying the velocity of
objects. The velocity is related to the space-time image
derivatives at one image location using an equation often called the gradient constraint equation. n. If one has access
to only two frames, or cannot estimate It, it is straightforward
to derive a closely related gradient constraint, in which It(x,
t) in is replaced by I(x, t) I(x, t + 1) I(x, t).

#### The Algorithm 
The Algorithm
Optical flow can be implemented by following the below
mentioned steps:
1) Compute the intensity of each pixel
2) For each pixel position compute the gradient matrix
and store an eigenvalue of matrix
3) Separate the high scoring pixels by flag matrix F and
region size k and flag region size f
4) Take the top n eigen values and use those for the
trackable features
5) The Gaussian random distribution is applied for speed
base
6) Next, warp one image, take derivatives of the other so
you dont need to re-compute the gradient after each
iteration
7) Repeat until complete


