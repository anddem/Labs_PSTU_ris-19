#include "pch.h"
#include "Calculator.h"

using namespace Creativity;

int main()
{
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);
  Application::Run(gcnew Calculator);

  return 0;
}
