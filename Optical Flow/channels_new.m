function Ik = channels_new(I, scale)
% This function takes an image and returns the different channels
% that need to be made out of it.
% Currently the channels are
% 1) Grayscale intensity.
% 2) Green - Red 
% 3) Green - Blue
% 4) x-derivative of intensity
% 5) y-derivative of intensity
% 2nd and 3rd components are scaled to increase numerical stability.

I = gaussianSmooth(I, 1.0) ;

if nargin < 2
	scale = 0.25 ;
end

[ht, wt, dt] = size(I) ;
Ik = zeros( ht, wt, dt ) ;

Ik(:, :, 1) = double(rgb2gray(I)) ;
% computing gradients
[Ik(:, :, dt-1) Ik(:, :, dt)] = imgGrad(Ik(:, :, 1)) ;
% now scaling down.
Ik(:, :, 2) = double(I(:, :, 2)) - double(I(:, :, 1)) ;
Ik(:, :, 3) = double(I(:, :, 2)) - double(I(:, :, 3)) ;
Ik(:, :, 2) = Ik(:, :, 2) * scale ;
Ik(:, :, 3) = Ik(:, :, 3) * scale ;
