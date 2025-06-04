# GDB Debugging Setup for CPP Chatbot - COMPLETED ✅

This project is now fully configured for debugging with GDB in Visual Studio Code.

## 🎉 Setup Complete!

The image loading error has been **FIXED** and the following debugging setup is ready to use:

### Issues Resolved:
1. ✅ **Image Loading Error Fixed**: Added proper error checking for image file loading
2. ✅ **Working Directory Fixed**: Updated debug configuration to run from `build/` directory
3. ✅ **Debug Symbols Enabled**: Project builds with `-g -O0` flags for debugging
4. ✅ **VS Code Integration**: Complete Run and Debug tab configuration

## How to Debug Using VS Code Run and Debug Tab

### **Step 1: Set Breakpoints**
- Open any source file (e.g., `src/chatgui.cpp`)
- Click in the left margin next to line numbers to set breakpoints
- Red dots will appear indicating breakpoints

### **Step 2: Start Debugging**
1. Open the **Run and Debug** view (`Ctrl+Shift+D`)
2. Select **"Debug Membot"** from the dropdown
3. Click the green **Start Debugging** button or press `F5`
4. The project will automatically build and start debugging

### **Step 3: Debug Controls**
- `F5`: Continue execution
- `F10`: Step Over (execute current line)
- `F11`: Step Into (enter function calls)
- `Shift+F11`: Step Out (exit current function)
- `Shift+F5`: Stop Debugging

### **Example Debugging Session**

Try setting a breakpoint on line 86 in `chatgui.cpp`:
```cpp
void ChatBotFrameImagePanel::render(wxDC &dc)
{
    // load background image from file
    wxString imgFile = imgBasePath + "sf_bridge.jpg";  // <- Set breakpoint here
```

When you start debugging, the debugger will pause here and you can:
- Inspect the `imgBasePath` variable
- Step through the image loading process
- Watch how the application handles the GUI rendering

## Configuration Files Created

### `.vscode/launch.json` ✅
- **"Debug Membot"**: Debug the main application
- **"Debug Tests"**: Debug the test suite
- Working directory set to `build/` for correct file paths

### `.vscode/tasks.json` ✅
- **build**: Build the project (default task)
- **clean**: Clean build artifacts  
- **configure**: Configure CMake with Debug

### `.vscode/c_cpp_properties.json` ✅
- IntelliSense configuration for code navigation

### `.vscode/settings.json` ✅
- CMake and C++ specific settings

## What Was Fixed

### Code Changes:
1. **Error Checking Added**: All image loading now includes proper validation
2. **File Existence Checks**: Prevents crashes when image files are missing
3. **Size Validation**: Ensures valid dimensions before image scaling

### Build Configuration:
1. **Debug Symbols**: `-g` flag enabled
2. **No Optimization**: `-O0` for accurate debugging
3. **Warning Flags**: `-Wall -Wextra` for better code quality

### Directory Structure:
- Application runs from `build/` directory where relative paths work correctly
- Images located at `../images/` relative to executable

## Ready to Use! 🚀

Your C++ chatbot project is now fully configured for debugging. You can:

- ✅ Use VS Code Run and Debug tab (no terminal needed)
- ✅ Set breakpoints and step through code
- ✅ Inspect variables and call stack
- ✅ Debug both the main application and tests
- ✅ Application runs without image loading errors

**Just press `F5` in VS Code to start debugging!**
