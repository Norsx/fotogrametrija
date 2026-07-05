function ExportMask2Workspace(fig)

% keyboard
Mask = fig.UserData.processedMask;


assignin('base', 'Mask', Mask);

