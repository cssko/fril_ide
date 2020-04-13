# Testing Plan

## Part I. Description of Overall Test Plan
To ensure a high quality end product, we are planning on testing all of the backend components of the IDE with mock data for normal, abnormal and boundary tests. We will create test cases for each feature before and after implementation to ensure that we satisfy requirements and ensure our implementation works smoothly (black and whitebox testing) and test each component individually and in conjunction (unit and integration testing). We also want to ensure that the application not only works, but meets certain non-functional requirements such as running the FRIL code quickly and efficiently or building an intuitive and customizable interface. We will develop performance tests for qualities like speed and conduct user testing to measure and gauge these attributes. 

## Part II. Test Case Descriptions

### Text Editor Tests
**TE.1.1 Built In Predicate Selection Test**<br/>
TE.1.2 Test whether the regex catches built in predicates and selects them for highlighting<br/>
TE.1.3 This test will be a backend test of the regex we use to select phrases as built-in predicates for highlighting.<br/>
TE.1.4 Inputs: String with varying number and kinds of FRIL built in predicates<br/>
TE.1.5 Outputs: FRIL built in predicates from the test string<br/>
TE.1.6 Normal<br/>
TE.1.7 Whitebox<br/>
TE.1.8 Functional<br/>
TE.1.9 Unit Test<br/>

**TE.2.1 Built In Predicate Selection Test**<br/>
TE.2.2 Test whether the regex catches variables and selects them for highlighting<br/>
TE.2.3 This test will be a backend test of the regex we use to select phrases as variables for highlighting. Variables in FRIL start with upper case letters.<br/> 
TE.2.4 Inputs: String with valid variables in FRIL with varying lengths and of various numbers
TE.2.5 Outputs: Valid FRIL variables in the test string<br/>
TE.2.6 Normal<br/>
TE.2.7 Whitebox<br/>
TE.2.8 Functional<br/>
TE.2.9 Unit Test<br/>

**TE.3.1 Built In Predicate Selection Test**<br/>
TE.3.2 Test whether the regex can differentiate between variables and predicates<br/>
TE.3.3 This test will be a backend test of the regex for selecting phrases as variables for highlighting. Variables in FRIL start with upper case letters. <br/>
TE.3.4 Inputs: String which is built in predicate that starts with capital letters and is thus a valid variable<br/>
TE.3.5 Outputs: Phrase is selected as a variable but not a built-in predicate<br/>
TE.3.6 Boundary<br/>
TE.3.7 Whitebox<br/>
TE.3.8 Functional<br/>
TE.3.9 Unit Test<br/>

### File Directory Tests
**FD.1.1: File Navigation Test**<br/>
FD.1.2: Test whether the contents of the Folder Tree View in the IDE are same opened from the user’s file system.<br/>
FD.1.3: Click on a folder in the Folder Tree View and check if the files in the folder are listed.<br/>
FD.1.4: Input: Open a directory in the file navigator<br/>
FD.1.5: Output: Files and folder names which correspond to files and folders in the specified directory<br/>
FD.1.6: Normal<br/>
FD.1.7: Blackbox<br/>
FD.1.8: Functional<br/>
FD.1.9: Unit<br/>

**FD.2.1: Folder Expansion/Hide Test**<br/>
FD.2.2: Test whether the folder expansion or folder hiding functionality works<br/>
FD.2.3: Click on the folder expand/folder hide button and verify that the folder hides or expands the list of files in the folder<br/>
FD.2.4: Input: Click on the expand/hide symbol in the file navigator for a folder<br/>
FD.2.5: Output: Folder expands or hides<br/>
FD.2.6: Normal<br/>
FD.2.7: Blackbox<br/>
FD.2.8: Functional<br/>
FD.2.9: Unit<br/>

**FD.3.1: Folder Opening Response Test**<br/>
FD.3.2: Test whether a folder is opened within an acceptable amount of time<br/>
FD.3.3: Automated test of whether a folder is opened within an acceptable amount of time <br/>
FD.3.4: Input: Open a folder using the file navigator<br/>
FD.3.5: Output: File opens within expected threshold of time<br/>
FD.3.6: Normal<br/>
FD.3.7: Blackbox<br/>
FD.3.8: Performance<br/>
FD.3.9: Unit<br/>

### Console Tests

**C.1.1 Console exception handling test**<br/>
C.1.2 Cause the console to crash and observe how the exception is handled<br/>
C.1.3 This test will ensure that the console responds to exceptions in ways that do not cause data loss to the user.<br/>
C.1.4 Inputs: An unhandled exception is injected in the console.<br/>
C.1.5 Outputs: The console is expected to save the existing knowledge base and reset.<br/>
C.1.6 Abnormal<br/>
C.1.7 Whitebox<br/>
C.1.8 Functional<br/>
C.1.9 Unit<br/>

**C.2.1 Console normal functioning test**<br/>
C.2.2 Type a FRIL command in the console and see if expected output is returned<br/>
C.2.3 This test will ensure that the console functions as expected when a user types FRIL commands.<br/>
C.2.4 Inputs: A FRIL command is typed into the console<br/>
C.2.5 Outputs: The console returns the expected output to that FRIL command<br/>
C.2.6 Normal<br/>
C.2.7 Blackbox<br/>
C.2.8 Functional<br/>
C.2.9 Unit<br/>

**C.3.1 Test: Console response time test**<br/>
C.3.1 Console response time test<br/>
C.3.2 Test whether console has a response time within expected tolerance<br/>
C.3.3 This test will ensure that the console has an adequate performance speed.<br/>
C.3.4 Inputs: Simple FRIL commands including queries will be entered into the console<br/>
C.3.5 Outputs: The time it takes for the FRIL commands to respond will be returned<br/>
C.3.6 Normal<br/>
C.3.7 Whitebox<br/>
C.3.8 Performance<br/>
C.3.9 Unit<br/>

### Settings Tests
**S.1.1 Console background color test**<br/>
S.1.2 Test whether console background color changes when the console background color is changed in the settings<br/>
S.1.3 This test will ensure that changes made within the settings menu for the console background color are reflected in the UI.<br/>
S.1.4 Inputs: A new color for the console background which is significantly different than the previous one<br/>
S.1.5 Outputs: The console background has the same color as specified in the settings<br/>
S.1.6 Normal<br/>
S.1.7 Blackbox<br/>
S.1.8 Functionality<br/>
S.1.9 Integrated<br/>

**S.2.1 Editor background color test**<br/>
S.2.2 Test whether editor background color changes when the editor background color is changed in the settings<br/>
S.2.3 This test will ensure that changes made within the settings menu for the editor background color are reflected in the UI.<br/>
S.2.4 Inputs: A new color for the editor which is significantly different than the previous one<br/>
S.2.5 Outputs: The editor has the same color as specified in the settings<br/>
S.2.6 Normal<br/>
S.2.7 Blackbox<br/>
S.2.8 Functionality<br/>
S.2.9 Integrated<br/>

**S.3.1 Editor background color response test**<br/>
S.3.2 Test how long it takes for the editor background color to change when it is changed in the settings<br/>
S.3.3 This test will ensure that changes made within the settings menu for the editor background color are reflected in the UI within an appropriate amount of time.<br/>
S.3.4 Inputs: A new color for the editor which is significantly different than the previous one<br/>
S.3.5 Outputs: Time taken for the editor to change to the color specified in the settings<br/>
S.3.6 Normal<br/>
S.3.7 Whitebox<br/>
S.3.8 Performance<br/>
S.3.9 Integrated<br/>

## Part III. Test Case Matrix

| Test ID        | Normal/Boundary/Abnormal | Blackbox/White box | Functional/Performance | Unit/Integrated |
|----------------|--------------------------|--------------------|------------------------|-----------------|
| Text Editor    |                          |                    |                        |                 |
| TE.1           | Normal                   | Whitebox           | Functional             | Unit            |
| TE.1           | Normal                   | Whitebox           | Functional             | Unit            |
| TE.1           | Boundary                 | Whitebox           | Functional             | Unit            |
|                |                          |                    |                        |                 |
| File Directory |                          |                    |                        |                 |
| FD.1           | Normal                   | Blackbox           | Functional             | Unit            |
| FD.2           | Normal                   | Blackbox           | Functional             | Unit            |
| FD.3           | Normal                   | Blackbox           | Performance            | Unit            |
|                |                          |                    |                        |                 |
| Console        |                          |                    |                        |                 |
| C.1            | Abnormal                 | Whitebox           | Functional             | Unit            |
| C.2            | Normal                   | Blackbox           | Functional             | Unit            |
| C.3            | Normal                   | Whitebox           | Performance            | Unit            |
|                |                          |                    |                        |                 |
| Settings       |                          |                    |                        |                 |
| S.1            | Normal                   | Blackbox           | Functional             | Integrated      |
| S.2            | Normal                   | Blackbox           | Functional             | Integrated      |
| S.3            | Normal                   | Whitebox           | Performance            | Integrated      |