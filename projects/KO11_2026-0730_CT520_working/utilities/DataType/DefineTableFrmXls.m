%% Guideline
% all the lookuptables are stored in lookuptable.c with const volatile
% qualifier. 
% Post process is necessary to add other qualifier if Ax address
% used.

%% Load simulink lookup Tables
clear ndata; 
clear text;
clear alldata;
[ndata, text, alldata] = xlsread('ParameterGenerator.xlsx','TableDefinition');
[n,m] = size(alldata);

for i = 2:1:n
    TableName = char(alldata(i,1));     % colunm 1  Table name
    eval([TableName, '= Simulink.LookupTable;']);
    
    TableSize = cell2mat(alldata(i,3));       %column 3 Table dimension
     contents = cell2mat(alldata(i,19));
    if isnan(contents)
        contents = '';
    end
    
    eval([TableName,'.Table.Description = contents;']); % column 19 description on table
    eval([TableName,'.Table.Value = ',cell2mat(alldata(i,4)),';']); %column4 Table value, cell2mat treat array with [] as string
    eval([TableName,'.Table.DataType  = cell2mat(alldata(i,5));']); %column5 Table data type
    contents = cell2mat(alldata(i,6));
    
    if (~isnumeric(contents))||(isnan(contents))
        contents = [];
    end
    
    eval([TableName,'.Table.Min  = contents;']); %column6 Table minimum, only numeric support
    contents = cell2mat(alldata(i,7));
    if (~isnumeric(contents))||(isnan(contents))
        contents = [];
    end
    
    eval([TableName,'.Table.Max  = contents;']); %column7 Table maximum, only numeric support
    contents = cell2mat(alldata(i,8));
    if isnan(contents)
        contents = '';
    end
    eval([TableName,'.Table.Unit  = contents;']); %column8 Table data type
    eval([TableName,'.Table.FieldName = ''tab'';']);
    for j=1:1:TableSize
        eval([TableName,'.Breakpoints(j).Value = ',cell2mat(alldata(i,4+j*5)),';']); %column4+5j breakpoint(j)
        eval([TableName,'.Breakpoints(j).DataType = char(cell2mat(alldata(i,5+j*5)));']); %column5+5j breakpoint(j) datatype
        contents = cell2mat(alldata(i,6+j*5));
        if (~isnumeric(contents))||(isnan(contents))
             contents = [];
        end
        eval([TableName,'.Breakpoints(j).Min = contents;']); %column5+5j breakpoint(j) datatype  
        contents = cell2mat(alldata(i,7+j*5));
        if (~isnumeric(contents))||(isnan(contents))
             contents = [];
        end
        eval([TableName,'.Breakpoints(j).Max = contents;']); %column5+5j breakpoint(j) datatype  
        contents = cell2mat(alldata(i,8+j*5));
        
        if isnan(contents)
             contents = '';
        end
        eval([TableName,'.Breakpoints(j).Unit = contents;']); %column5+5j breakpoint(j) datatype     
        eval([TableName,'.Breakpoints(j).FieldName = [''bp'',num2str(j)];']);
    end
     
    eval([TableName,'.StructTypeInfo.Name = replace(TableName,''_T'',''ST'');']);     % structure name
    eval([TableName,'.StructTypeInfo.DataScope = ''Exported'';']);              % structure exported
    eval([TableName,'.StructTypeInfo.HeaderFileName = ''lookuptabletype.h'';']);   % h file structure defined

    eval([TableName, '.CoderInfo.StorageClass=''Custom'';']);
    eval([TableName, '.CoderInfo.CustomStorageClass=''ConstVolatile'';']);
    eval([TableName, '.CoderInfo.CustomAttributes.HeaderFile=''lookuptable.h'';']);
    eval([TableName, '.CoderInfo.CustomAttributes.DefinitionFile=''lookuptable.c'';']);

    clear TableName;
    clear TableSize;
end

%% clear
clear Para ParameterName
clear n m ndata text alldata;

%% Load simulink lookup Tables
clear ndata; 
clear text;
clear alldata;
[ndata, text, alldata] = xlsread('ParameterGeneratorP1.xlsx','TableDefinition');
[n,m] = size(alldata);

for i = 2:1:n
    TableName = char(alldata(i,1));     % colunm 1  Table name
    eval([TableName, '= Simulink.LookupTable;']);
    
    TableSize = cell2mat(alldata(i,3));       %column 3 Table dimension
     contents = cell2mat(alldata(i,19));
    if isnan(contents)
        contents = '';
    end
    
    eval([TableName,'.Table.Description = contents;']); % column 19 description on table
    eval([TableName,'.Table.Value = ',cell2mat(alldata(i,4)),';']); %column4 Table value, cell2mat treat array with [] as string
    eval([TableName,'.Table.DataType  = cell2mat(alldata(i,5));']); %column5 Table data type
    contents = cell2mat(alldata(i,6));
    
    if (~isnumeric(contents))||(isnan(contents))
        contents = [];
    end
    
    eval([TableName,'.Table.Min  = contents;']); %column6 Table minimum, only numeric support
    contents = cell2mat(alldata(i,7));
    if (~isnumeric(contents))||(isnan(contents))
        contents = [];
    end
    
    eval([TableName,'.Table.Max  = contents;']); %column7 Table maximum, only numeric support
    contents = cell2mat(alldata(i,8));
    if isnan(contents)
        contents = '';
    end
    eval([TableName,'.Table.Unit  = contents;']); %column8 Table data type
    eval([TableName,'.Table.FieldName = ''tab'';']);
    for j=1:1:TableSize
        eval([TableName,'.Breakpoints(j).Value = ',cell2mat(alldata(i,4+j*5)),';']); %column4+5j breakpoint(j)
        eval([TableName,'.Breakpoints(j).DataType = char(cell2mat(alldata(i,5+j*5)));']); %column5+5j breakpoint(j) datatype
        contents = cell2mat(alldata(i,6+j*5));
        if (~isnumeric(contents))||(isnan(contents))
             contents = [];
        end
        eval([TableName,'.Breakpoints(j).Min = contents;']); %column5+5j breakpoint(j) datatype  
        contents = cell2mat(alldata(i,7+j*5));
        if (~isnumeric(contents))||(isnan(contents))
             contents = [];
        end
        eval([TableName,'.Breakpoints(j).Max = contents;']); %column5+5j breakpoint(j) datatype  
        contents = cell2mat(alldata(i,8+j*5));
        
        if isnan(contents)
             contents = '';
        end
        eval([TableName,'.Breakpoints(j).Unit = contents;']); %column5+5j breakpoint(j) datatype     
        eval([TableName,'.Breakpoints(j).FieldName = [''bp'',num2str(j)];']);
    end
     
    eval([TableName,'.StructTypeInfo.Name = replace(TableName,''_T'',''ST'');']);     % structure name
    eval([TableName,'.StructTypeInfo.DataScope = ''Exported'';']);              % structure exported
    eval([TableName,'.StructTypeInfo.HeaderFileName = ''lookuptabletypeP1.h'';']);   % h file structure defined

    eval([TableName, '.CoderInfo.StorageClass=''Custom'';']);
    eval([TableName, '.CoderInfo.CustomStorageClass=''ConstVolatile'';']);
    eval([TableName, '.CoderInfo.CustomAttributes.HeaderFile=''lookuptableP1.h'';']);
    eval([TableName, '.CoderInfo.CustomAttributes.DefinitionFile=''lookuptableP1.c'';']);

    clear TableName;
    clear TableSize;
end