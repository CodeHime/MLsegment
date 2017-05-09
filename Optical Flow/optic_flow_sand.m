% optical flow function

function [velocity_image,u, v] = optic_flow_sand( img1, img2, num )

alpha_global = 10.0 ;
alpha_local = 15.0 ;

% height width and channels in image
[ht, wt, dt] = size( img1 ) ;
% num_levels = round( power( 0.9, 50 / min( ht, wt ) ) ) 
num_levels = round( log10( 30 / min( ht, wt ) ) / log10( 0.9 ) ) 

%
u = zeros( fix( power( 0.9, num_levels ) * ht )+1, fix( power( 0.9, num_levels ) * wt )+1 ) ;
v = zeros( fix( power( 0.9, num_levels ) * ht )+1, fix( power( 0.9, num_levels ) * wt ) +1) ;
du = zeros( fix( power( 0.9, num_levels ) * ht )+1, fix( power( 0.9, num_levels ) * wt ) +1) ;
dv = zeros( fix( power( 0.9, num_levels ) * ht )+1, fix( power( 0.9, num_levels ) * wt )+1 ) ;

num_channels = dt ;
i=num_levels;
%for i = num_levels : -1 : 8
    % apply gaussian smoothing/blur to the image and then rescale according
    % to the resolution needed
	im1_hr = gaussianRescaling( img1, power( 0.9, i ) ) ;
	im2_hr = gaussianRescaling( img2, power( 0.9, i ) ) ;
	[htn, wtn, dtn] = size( im1_hr ) ;

    % convert to greyscale, find derivative and convert to a aplha channel
 	alphaImg = alpha_local * getalphaImg( im2_hr ) + alpha_global * ones( htn, wtn ) ;

 	im2_hrw = uint8( mywarp_rgb( double( im2_hr ), u, v ) ) ; % warp images.

    % computing different channels of respective images
 	I1 = channels_new( im1_hr ) ;
 	I2 = channels_new( im2_hrw ) ;

    %x and y derivative of the image, i.e. gradient matrix
	[Ikx Iky] = imgGrad( I2 ) ;
    
    %difference between the images
	Ikz = I2 - I1 ;
 
    % applying gaussian distribution
 	alphaImg = alpha_local * getalphaImg( im2_hr ) + alpha_global * ones( htn, wtn ) ;
 
    
	[du, dv] = resolutionProcess_sand( Ikz, Ikx, Iky, alphaImg, 1.9, u, v, dt, 500, num ) ;

	figure; 
    quiver( u+du, v+dv ) ;
    velocity_image=getframe(gcf);
	title( sprintf( 'Optical flow at resolution %d', i ) ) ;
	axis ij ;