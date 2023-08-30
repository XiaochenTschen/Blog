```matlab
% File name: MyFunctionWithTest.m

% Simple function to add two numbers
function result = addTwoNumbers(a, b)
    result = a + b;
end

% Test class for addTwoNumbers
classdef MyFunctionTest < matlab.unittest.TestCase
    properties (TestParameter)
        a = {1, -1, 0};
        b = {2, -2, 0};
        expectedOutput = {3, -3, 0};
    end
    
    methods (Test)
        function testAdditionWithParameters(testCase, a, b, expectedOutput)
            result = addTwoNumbers(a, b);
            testCase.verifyEqual(result, expectedOutput);
        end
    end
end

% Run the tests
results = runtests('MyFunctionWithTest.m');
disp(results);

```