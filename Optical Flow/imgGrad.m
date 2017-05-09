function [xd, yd] = imgGrad( I , sigma )
% This function outputs the x-derivative and y-derivative of the
% input I. If I is 3D, then derivatives of each channel are
% available in xd and yd.

if nargin < 2
	sigma = 1.0 ; % default sigma for gaussian.
end
if ~isequal( class( I ), 'double' )
	I = double( I ) ;
end

gd = gaussDeriv( sigma ) ;

% Right now the convolution takes the middle part of the result
% This can be changed as per our requirement.
xd = convn( I, gd, 'same' ) ;
yd = convn( I, gd', 'same' ) ;
