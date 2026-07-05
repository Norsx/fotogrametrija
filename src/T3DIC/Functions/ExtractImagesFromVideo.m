clear all
clc

%%
Path = 'C:\Users\zapla\OneDrive - Fakultet strojarstva i brodogradnje\Work\Razno\RITEH\HMD_B3_1_popravni\';
vidObj = VideoReader([Path,'HMD B3-1_popravni.MOV']);
numFrames = 0;
while hasFrame(vidObj)
    F = readFrame(vidObj);    
    numFrames = numFrames + 1;  
    
 str = sprintf('image_%08d',numFrames);
 imwrite(F,[Path,'Images\',str,'.tif']);
end
