#include "LoginForm.h"
#include "MainForm.h"
#include "func.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace LepWebGUI; 

[STAThreadAttribute]
int main(array<String^>^ args)
{
    // Enable visual styles and set rendering defaults
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Run both windows for debug

    /*LoginForm^ login = gcnew LoginForm();
    MainForm^ main = gcnew MainForm();

    login->Show();
    main->Show();

    Application::Run(main);*/

    // Launch the login form
    Application::Run(gcnew LoginForm()); // Launch Login Window

    return 0;
}