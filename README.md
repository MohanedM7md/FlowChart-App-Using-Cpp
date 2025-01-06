# FlowChart Windows Application Using C++
![Flow Chart](https://github.com/user-attachments/assets/61ca0971-7bca-4235-b763-2664da2544b3)

## About
This Windows Flow Chart Application is a user-friendly tool for designing, editing, and managing flow charts, fully built using C++. It allows users to visually map out processes, workflows, or algorithms with ease providing an intuitive interface for creating professional flow charts. Designed for simplicity and efficiency, this application helps streamline complex workflows into clear, structured visualizations. Whether you're planning software architectures, business processes, or educational diagrams, this tool provides an intuitive interface for creating professional flow charts. 
## Contributors
- Amr Ashraf
- Fady Samy
- Mohaned Mohamed
## Features
- Modern Easy to Use GUI
- Drag-and-Drop Interface
- Smooth Connectors
- Auto-Align and Snap
- Copy/Paste/Delete Shapes
- FlowChart Save/Load
- Auto FlowChart Validation
## Project Structure

```C++
/flowchart-app
|-- src
|   |-- main.cpp
|   |-- ApplicationManager.cpp
|-- include
|   |-- ApplicationManager.h
|-- Statements
|   |-- Statement.cpp
|   |-- Start.cpp
|   |-- End.cpp
|   |-- OpAssign.cpp
|   |-- Read.cpp
|   |-- ValueAssign.cpp
|   |-- VarAssign.cpp
|   |-- Write.cpp
|-- include
|   |-- Statement.h
|   |-- Start.h
|   |-- End.h
|   |-- OpAssign.h
|   |-- Read.h
|   |-- ValueAssign.h
|   |-- VarAssign.h
|   |-- Write.h
|--Actions
|   |-- Action.cpp
---include
|   |-- Action.h
|-- diagrams
|   |-- ClassDiagram.cd
```
## Demo
https://github.com/user-attachments/assets/cdb02d17-950b-41b0-8bd5-810af6758adf

## Installation
Note: To run the app, make sure you have Visual Studio installed.
1. Clone the repository
```
 https://github.com/OmarIsmail11/FlowChart-App-Using-Cpp.git
```
2. Navigate to the project directory
```
 cd FolderName
```
3. In Visual Studio run the main.cpp file

Note: Make Sure all the source files are properly downloaded as sometimes some of the project files aren't all loaded in Visual Studio and results in a Linker error (LNK).
If this error occured, copy the missing source files in VS from the folder itself (project directory) and paste in VS manually. This may happen in statements & actions files.  

