   fileTxt = fileread(plfile);
 %  fileHdl = fopen(plfile,'w');
   pos = strfind(fileTxt,'#set the main node');
   posArray = strfind(fileTxt(pos:length(fileTxt)), '''');
   firstQuotation = posArray(1) + pos-1;
   lastQuotation = posArray(2) + pos-1;
   fileTxt = [fileTxt(1:firstQuotation),...
                ecuNode,...
               fileTxt(lastQuotation:length(fileTxt))];
    fileHdl = fopen(plfile,'w');
    fprintf(fileHdl,'%s',fileTxt);
    fclose(fileHdl);
    %% clear
    clear fileTxt pos posArray firstQuotation lastQuotation fileHdl

