#pragma once

#include <wrl.h>
#include <Shobjidl.h>
#include <winrt/base.h>

using namespace Microsoft::WRL;

struct __declspec(uuid("4ff34566-afc6-4995-9b5f-3f0dae116f8f"))

OpenHere: public RuntimeClass<RuntimeClassFlags<ClassicCom | InhibitFtmBase>, IExplorerCommand, IObjectWithSite>
{
    IFACEMETHOD(Invoke) (IShellItemArray * psiItemArray, IBindCtx * pBindContext);
    IFACEMETHOD(GetToolTip) (IShellItemArray* psiItemArray, LPWSTR* ppszInfoTip);
    IFACEMETHOD(GetTitle) (IShellItemArray* psiItemArray, LPWSTR* ppszName);
    IFACEMETHOD(GetState) (IShellItemArray* psiItemArray, BOOL fOkToBeSlow, EXPCMDSTATE* pCmdState);
    IFACEMETHOD(GetIcon) (IShellItemArray* psiItemArray, LPWSTR* ppszIcon);
    IFACEMETHOD(GetFlags) (EXPCMDFLAGS* pFlags);
    IFACEMETHOD(GetCanonicalName) (GUID* pguidCommandName);
    IFACEMETHOD(EnumSubCommands) (IEnumExplorerCommand** ppEnum);

    IFACEMETHOD(SetSite) (IUnknown* site) noexcept;
    IFACEMETHOD(GetSite) (REFIID riid, void** site) noexcept;

private:
    winrt::com_ptr<IUnknown> site;

    winrt::com_ptr<IShellItem> GetLocationFromSite();
    winrt::com_ptr<IShellItem> GetLocation(winrt::com_ptr<IShellItemArray> item_array);
};

CoCreatableClass(OpenHere);

