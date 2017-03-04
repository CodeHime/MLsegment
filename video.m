runLoop = true;
numPts = 0;
frameCount = 0;
obj.reader = vision.VideoFileReader('a.mp4');

        % Create two video players, one to display the video,
        % and one to display the foreground mask.
        obj.videoPlayer = vision.VideoPlayer('Position', [100 100 [640, 480]+30]);
        obj.maskPlayer = vision.VideoPlayer('Position', [100 100 [640, 480]+30]);

        % Create System objects for foreground detection and blob analysis

        % The foreground detector is used to segment moving objects from
        % the background. It outputs a binary mask, where the pixel value
        % of 1 corresponds to the foreground and the value of 0 corresponds
        % to the background.

        obj.detector = vision.ForegroundDetector('NumGaussians', 3, ...
            'NumTrainingFrames', 40, 'MinimumBackgroundRatio', 0.1);

        % Connected groups of foreground pixels are likely to correspond to moving
        % objects.  The blob analysis System object is used to find such groups
        % (called 'blobs' or 'connected components'), and compute their
        % characteristics, such as area, centroid, and the bounding box.

        obj.blobAnalyser = vision.BlobAnalysis('BoundingBoxOutputPort', true, ...
            'AreaOutputPort', true, 'CentroidOutputPort', true, ...
            'MinimumBlobArea', 400);
        
while runLoop && frameCount < 400 
    frameCount = frameCount + 1;
    frame = obj.reader.step();
    frame = im2uint8(frame);
    mask = obj.detector.step(frame);
    mask = imopen(mask, strel('rectangle', [3,3]));
    mask = imclose(mask, strel('rectangle', [15, 15]));
    mask = imfill(mask, 'holes');
    mask = uint8(repmat(mask, [1, 1, 3])) .* 255;
    obj.maskPlayer.step(mask);
    obj.videoPlayer.step(frame);
end