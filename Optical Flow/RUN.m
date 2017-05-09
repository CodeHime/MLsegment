%Main program calling optical flow
clear;

%read the video file and find the number of frames in the video. 
video = VideoReader('cut1.avi'); 
numFrames = video.NumberOfFrames; 
%initialize the variables. 
com=zeros(1,numFrames); 
speed=zeros(1,numFrames); 
position=zeros(1,numFrames); 
d=zeros(1,numFrames); 

%read the video file and find the number of frames in the video. 
video = VideoReader('cut1.avi'); 
numFrames = video.NumberOfFrames; 
%initialize the variables. 
com=zeros(1,numFrames); 
speed=zeros(1,numFrames); 
position=zeros(1,numFrames); 
d=zeros(1,numFrames); 
%for loop to manipulate each frame 

v = VideoWriter('test.avi');
open(v); 

for i = 440:numFrames
    writeVideo(v,read(video, i));
end

close(v);

v = VideoWriter('velocity1.avi');
open(v);

img1 = read(video, 440); 
img1 = double(img1);
i=i+1;
img2 = read(video, 441); 
img2 = double(img2);
velocity_image=optic_flow_sand( img1, img2, 0 );
velobw=im2bw(velocity_image.cdata);
writeVideo(v,velocity_image);

%for loop to manipulate each frame 
for i = 441:numFrames-1
    %read each frame of video and manipulate it. 
    img1 = read(video, i); 
    img1 = double(img1);
    i=i+1;
    img2 = read(video, i); 
    img2 = double(img2);
    
%     img1=imread('car0.png');
%     img2=imread('car1.png');
    velocity_pre=velobw;
	velocity_image=optic_flow_sand( img1, img2, i );
    velobw=im2bw(velocity_image.cdata);
    
    diff=abs(velobw-velocity_pre);
    
    writeVideo(v,velocity_image);
end

close(v);


