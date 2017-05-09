function alphaImg = getalphaImg( img, alpha_cov )

if nargin < 2
	alpha_cov = 2.0 ;
end

%convert to greyscale
img_g = rgb2gray( img ) ;
% take x and y derivative of image, i.e. identify where the colour intensity is changing
[ix, iy] = imgGrad( img_g );

% apply guassian distribution to the image
alphaImg = ix .^ 2 + iy .^ 2 ;
alphaImg = exp( -alphaImg / ( 2 * alpha_cov .^ 2 ) ) ;
alphaImg = alphaImg / sqrt( 2 * pi * alpha_cov .^ 2 ) ;
