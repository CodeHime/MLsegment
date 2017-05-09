function warpedim = mywarp_rgb( im1, u, v )
%

[h w d] = size(im1) ;

[uc vc] = meshgrid( 1:w, 1:h ) ;

uc1 = uc + u ;
vc1 = vc + v ;

warpedim = zeros( size(im1) ) ;
tmp = zeros(h, w) ;

tmp(:) = interp2(uc, vc, double(squeeze(im1(:, :, 1))), uc1(:), vc1(:), 'bilinear') ;
warpedim(:, :, 1) = tmp ;
tmp(:) = interp2(uc, vc, double(squeeze(im1(:, :, 2))), uc1(:), vc1(:), 'bilinear') ;
warpedim(:, :, 2) = tmp ;
tmp(:) = interp2(uc, vc, double(squeeze(im1(:, :, 3))), uc1(:), vc1(:), 'bilinear') ;
warpedim(:, :, 3) = tmp ;
