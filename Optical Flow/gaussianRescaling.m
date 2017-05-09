function img_scaled = gaussianRescaling(img, scale_factor, sigma)

if nargin < 3
	sigma = 1.0; % default.
end

if scale_factor < eps
	disp('Too small a scaling factor!!') ;
	return ;
end

% Now apply Gaussian smoothing to the input image. 
img_smooth = gaussianSmooth(img, 1.0/scale_factor, 1e-3) ;

% Now create and fill the new image
img_scaled = imresize(img_smooth, scale_factor, 'bilinear', 0);
