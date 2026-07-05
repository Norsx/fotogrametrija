answer = 'No';
while ~strcmpi(answer,'Yes')
    CreateMesh
    answer = questdlg('Satisfied?', ...
    	'Mesh generation', ...
    	'Yes','No','Yes');
end