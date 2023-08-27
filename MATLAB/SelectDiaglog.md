### 如何利用MATLAB Select Diaglog来选择一个或者多个选项，并返回该选项所代表的字符串。
示例代码如下：
```matlab
function selectedOptions = getSelectedOptions()

    % 选项列表
    options = {'Option 1', 'Option 2', 'Option 3', 'Option 4'};

    % 使用listdlg创建选择窗口
    [index, ok] = listdlg('PromptString', 'Select an option:',...
                          'SelectionMode', 'multiple',...
                          'ListString', options);

    % 如果用户点击"OK"并选择了选项，则返回选择的选项文本，否则返回空
    if ok
        selectedOptions = options(index);
    else
        selectedOptions = {};
    end

end
```