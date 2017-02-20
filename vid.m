clc;
close all;
clear all;

vidName = 'tempvid.mp4';
vidInstance = VideoReader(vidName);

outFolder = fullfile(cd, 'frames');
if ~exist(outFolder, 'dir')
	mkdir(outFolder);
end

frameCount = vidInstance.NumberOfFrames;
frameWrittenCount = 0;

for t = 1 : frameCount
    currentFrame = read(vidInstance, t);
    outputFilePrefix = sprintf('%3.3d.png', t);
    outputFileName = fullfile(outFolder, outputFilePrefix);
    imwrite(currentFrame, outputFileName, 'png');
    frameWrittenCount = frameWrittenCount + 1;
end