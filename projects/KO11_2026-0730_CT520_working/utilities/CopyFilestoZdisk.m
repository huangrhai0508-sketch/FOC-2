%% Guideline
% in the following,  cfile and mfile shall be changed.
% cfile useful segment format shall be checked
% FID DFC destitation path shall be checked
% cfile path: cfilepath/../sfun/DSM
% mfile path: mfilepath/../controller
p1 = mfilename('fullpath');
[pathstr,name,ext]=fileparts(p1);
pos_v = strfind(pathstr,filesep);

sourcepath = pathstr(1:pos_v(end)-1) ;
destpath = 'z:';

copyfile([sourcepath filesep 'controller'],[destpath filesep 'controller'],'f');
copyfile([sourcepath filesep 'utilities'],[destpath filesep 'utilities'],'f');