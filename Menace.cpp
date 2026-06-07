
// ============================================================
// MENACE CLIENT v1.0
// Minecraft 1.16.5 + 1.21.4 | Win 7/8/10/11
// ============================================================
#include <windows.h>
#include <d3d11.h>
#include <dxgi.h>
#include <vector>
#include <atomic>
#include <thread>
#include <mutex>
#include <random>
#include <TlHelp32.h>
#include <psapi.h>
#include <string>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "psapi.lib")

namespace ImGui {
    #define IMGUI_VERSION "1.90.4"
    #define IMGUI_DISABLE_OBSOLETE_FUNCTIONS
    #define IMGUI_DISABLE_DEFAULT_ALLOCATORS
    #define IM_ASSERT(_EXPR) ((void)(_EXPR))
    typedef unsigned int ImU32; typedef unsigned short ImU16; typedef unsigned char ImU8;
    struct ImVec2 { float x, y; ImVec2(float _x=0,float _y=0):x(_x),y(_y){} };
    struct ImVec4 { float x,y,z,w; ImVec4(float _x=0,float _y=0,float _z=0,float _w=0):x(_x),y(_y),z(_z),w(_w){} };
    enum ImGuiWindowFlags_ { ImGuiWindowFlags_None=0, ImGuiWindowFlags_NoResize=1<<1, ImGuiWindowFlags_NoCollapse=1<<5, ImGuiWindowFlags_AlwaysAutoResize=1<<7 };
    enum ImGuiInputTextFlags_ { ImGuiInputTextFlags_None=0 };
    enum ImGuiColorEditFlags_ { ImGuiColorEditFlags_None=0, ImGuiColorEditFlags_AlphaBar=1<<1, ImGuiColorEditFlags_NoInputs=1<<5 };
    struct ImGuiStyle {
        float Alpha=1.0f,WindowRounding=0.0f,FrameRounding=0.0f,ScrollbarRounding=0.0f,GrabRounding=0.0f,TabRounding=0.0f,PopupRounding=0.0f;
        ImVec2 WindowPadding=ImVec2(8,8),FramePadding=ImVec2(4,3),ItemSpacing=ImVec2(8,4);
        float WindowBorderSize=1.0f,FrameBorderSize=0.0f,PopupBorderSize=1.0f;
        bool AntiAliasedLines=true,AntiAliasedFill=true;
        struct { ImVec4 WindowBg,ChildBg,PopupBg,Border,BorderShadow,FrameBg,FrameBgHovered,FrameBgActive,TitleBg,TitleBgActive,TitleBgCollapsed,ScrollbarBg,ScrollbarGrab,ScrollbarGrabHovered,ScrollbarGrabActive,CheckMark,SliderGrab,SliderGrabActive,Button,ButtonHovered,ButtonActive,Header,HeaderHovered,HeaderActive,Separator,SeparatorHovered,SeparatorActive,ResizeGrip,ResizeGripHovered,ResizeGripActive,Tab,TabHovered,TabActive,TabUnfocused,TabUnfocusedActive,Text,TextDisabled; } Colors;
        ImGuiStyle() {
            Colors.WindowBg=ImVec4(0.06f,0.06f,0.06f,0.94f);Colors.ChildBg=ImVec4(0.06f,0.06f,0.06f,0.00f);Colors.PopupBg=ImVec4(0.08f,0.08f,0.08f,0.94f);
            Colors.Border=ImVec4(0.43f,0.43f,0.50f,0.50f);Colors.FrameBg=ImVec4(0.16f,0.16f,0.16f,0.54f);Colors.FrameBgHovered=ImVec4(0.26f,0.26f,0.26f,0.40f);
            Colors.FrameBgActive=ImVec4(0.26f,0.26f,0.26f,0.67f);Colors.TitleBg=ImVec4(0.04f,0.04f,0.04f,1.00f);Colors.TitleBgActive=ImVec4(0.16f,0.16f,0.16f,1.00f);
            Colors.ScrollbarBg=ImVec4(0.02f,0.02f,0.02f,0.53f);Colors.ScrollbarGrab=ImVec4(0.31f,0.31f,0.31f,1.00f);Colors.ScrollbarGrabHovered=ImVec4(0.41f,0.41f,0.41f,1.00f);
            Colors.ScrollbarGrabActive=ImVec4(0.51f,0.51f,0.51f,1.00f);Colors.CheckMark=ImVec4(0.26f,0.59f,0.98f,1.00f);Colors.SliderGrab=ImVec4(0.24f,0.52f,0.88f,1.00f);
            Colors.SliderGrabActive=ImVec4(0.26f,0.59f,0.98f,1.00f);Colors.Button=ImVec4(0.26f,0.59f,0.98f,0.40f);Colors.ButtonHovered=ImVec4(0.26f,0.59f,0.98f,1.00f);
            Colors.ButtonActive=ImVec4(0.06f,0.53f,0.98f,1.00f);Colors.Header=ImVec4(0.26f,0.59f,0.98f,0.31f);Colors.HeaderHovered=ImVec4(0.26f,0.59f,0.98f,0.80f);
            Colors.HeaderActive=ImVec4(0.26f,0.59f,0.98f,1.00f);Colors.Separator=ImVec4(0.43f,0.43f,0.50f,0.50f);Colors.ResizeGrip=ImVec4(0.26f,0.59f,0.98f,0.20f);
            Colors.ResizeGripHovered=ImVec4(0.26f,0.59f,0.98f,0.67f);Colors.ResizeGripActive=ImVec4(0.26f,0.59f,0.98f,0.95f);Colors.Tab=ImVec4(0.16f,0.16f,0.16f,0.86f);
            Colors.TabHovered=ImVec4(0.26f,0.59f,0.98f,0.80f);Colors.TabActive=ImVec4(0.20f,0.20f,0.20f,1.00f);Colors.TabUnfocused=ImVec4(0.06f,0.06f,0.06f,0.97f);
            Colors.TabUnfocusedActive=ImVec4(0.16f,0.16f,0.16f,1.00f);Colors.Text=ImVec4(1.00f,1.00f,1.00f,1.00f);Colors.TextDisabled=ImVec4(0.50f,0.50f,0.50f,1.00f);
        }
    };
    struct ImGuiIO { float Framerate=60.0f; bool WantCaptureMouse=false,WantCaptureKeyboard=false; const char* IniFilename=nullptr; const char* LogFilename=nullptr; };
    struct ImGuiContext { ImGuiStyle Style; ImGuiIO IO; };
    inline ImGuiContext* GImGui = nullptr;
    inline ImGuiContext* CreateContext() { GImGui = new ImGuiContext(); return GImGui; }
    inline ImGuiIO& GetIO() { return GImGui->IO; }
    inline ImGuiStyle& GetStyle() { return GImGui->Style; }
    struct ImDrawList { std::vector<float> m_VertexBuffer; std::vector<ImU32> m_IndexBuffer; std::vector<void*> m_CmdBuffer;
        void AddRect(ImVec2 a, ImVec2 b, ImU32 col, float rounding=0, int flags=0, float thickness=1.0f) {}
        void AddRectFilled(ImVec2 a, ImVec2 b, ImU32 col, float rounding=0, int flags=0) {}
        void AddText(ImVec2 pos, ImU32 col, const char* text) {}
        void AddLine(ImVec2 a, ImVec2 b, ImU32 col, float thickness=1.0f) {}
        void AddCircle(ImVec2 center, float radius, ImU32 col, int segments=0, float thickness=1.0f) {}
        void AddCircleFilled(ImVec2 center, float radius, ImU32 col, int segments=0) {}
    };
    inline ImDrawList* GetBackgroundDrawList() { static ImDrawList dl; return &dl; }
    inline bool Begin(const char* name, bool* p_open=nullptr, int flags=0) { return true; }
    inline void End() {}
    inline bool BeginTabBar(const char* id, int flags=0) { return true; }
    inline void EndTabBar() {}
    inline bool BeginTabItem(const char* label, bool* p_open=nullptr, int flags=0) { return true; }
    inline void EndTabItem() {}
    inline bool BeginChild(const char* id, ImVec2 size=ImVec2(0,0), bool border=false, int flags=0) { return true; }
    inline void EndChild() {}
    inline bool BeginPopup(const char* id, int flags=0) { return true; }
    inline void EndPopup() {}
    inline void OpenPopup(const char* id) {}
    inline void Separator() {}
    inline void Spacing() {}
    inline void SameLine(float offset=0, float spacing=-1) {}
    inline void Indent(float w=0) {}
    inline void Unindent(float w=0) {}
    inline void Text(const char* fmt, ...) {}
    inline void TextColored(ImVec4 col, const char* fmt, ...) {}
    inline void TextDisabled(const char* fmt, ...) {}
    inline void BulletText(const char* fmt, ...) {}
    inline bool Checkbox(const char* label, bool* v) { return false; }
    inline bool Button(const char* label, ImVec2 size=ImVec2(0,0)) { return false; }
    inline bool SmallButton(const char* label) { return false; }
    inline bool RadioButton(const char* label, int* v, int btn) { return false; }
    inline bool InputText(const char* label, char* buf, size_t buf_size, int flags=0) { return false; }
    inline bool SliderFloat(const char* label, float* v, float v_min, float v_max, const char* fmt="%.3f", float power=1.0f) { return false; }
    inline bool SliderInt(const char* label, int* v, int v_min, int v_max, const char* fmt="%d") { return false; }
    inline bool Combo(const char* label, int* curr, const char* items) { return false; }
    inline bool ColorEdit3(const char* label, float col[3], int flags=0) { return false; }
    inline bool ColorEdit4(const char* label, float col[4], int flags=0) { return false; }
    inline bool CollapsingHeader(const char* label, int flags=0) { return false; }
    inline void SetNextWindowSize(ImVec2 size, int cond=0) {}
    inline void SetNextWindowPos(ImVec2 pos, int cond=0) {}
    inline void PushStyleColor(int idx, ImVec4 col) {}
    inline void PopStyleColor(int cnt=1) {}
    inline void PushID(const char* id) {}
    inline void PopID() {}
    inline bool IsItemClicked(int button=0) { return false; }
    inline ImVec2 GetContentRegionAvail() { return ImVec2(500,400); }
    inline ImVec2 CalcTextSize(const char* text) { return ImVec2(50,14); }
    inline void StyleColorsDark() {}
    inline ImU32 ColorConvertFloat4ToU32(ImVec4 c) { return ((ImU32)(c.w*255)<<24)|((ImU32)(c.x*255)<<16)|((ImU32)(c.y*255)<<8)|(ImU32)(c.z*255); }
    #define IM_COL32(r,g,b,a) (((ImU32)(a)<<24)|((ImU32)(b)<<16)|((ImU32)(g)<<8)|(ImU32)(r))
}
namespace ImGui_ImplDX11 { inline bool Init(ID3D11Device* dev, ID3D11DeviceContext* ctx) { return true; } inline void NewFrame() {} inline void RenderDrawData(void*) {} }
namespace ImGui_ImplWin32 { inline bool Init(HWND hwnd) { return true; } inline void NewFrame() {} }

enum class MCVer{UNKNOWN,V1_16_5,V1_21_4};MCVer gV=MCVer::UNKNOWN;
struct A{uintptr_t gp=0,gw=0,gt=0,gpl=0,w2s=0,gbr=0,hv=0,iog=0,sp=0;int plo=0;uintptr_t brv=0;}gA;
struct SV{const char*s;int r;int fb;};
const char*GP165="48 8B 0D ? ? ? ? 48 85 C9 0F 84",*GW165="48 8B 05 ? ? ? ? 48 8B 88 ? ? ? ?",*GT165="F3 0F 10 05 ? ? ? ? F3 0F 59 C1";
const char*GP214="48 8B 05 ? ? ? ? 48 8B 80 ? ? ? ? C3",*GW214="48 8B 0D ? ? ? ? 48 85 C9 74 ?",*GT214="F3 0F 10 05 ? ? ? ? F3 0F 59 C1 C3";
SV vPL[]={{"48 8B 87 B8 00 00 00 48 85 C0 74",-1,0xB8},{"48 8B 87 C0 00 00 00 48 85 C0 74",-1,0xC0},{"48 8B 87 C8 00 00 00 48 85 C0",-1,0xC8},{"48 8B 87 D0 00 00 00 48 85 C0",-1,0xD0},{"48 8B 87 B0 00 00 00 48 85 C0",-1,0xB0},{"48 8B 87 E0 00 00 00 48 85 C0",-1,0xE0},{"48 8B 87 90 00 00 00 48 85 C0",-1,0x90},{"48 8B 87 80 00 00 00 48 85 C0",-1,0x80},{"48 8B 87 70 00 00 00 48 85 C0",-1,0x70},{0,0,0}};
SV vW2[]={{"48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? F3 0F 10 05",-1,0},{"48 89 5C 24 ? 48 89 74 24 ? 48 83 EC ? F3 0F 10",-1,0},{"48 89 5C 24 ? 57 48 83 EC ? F3 0F 10 44 24",-1,0},{"40 53 48 83 EC ? F3 0F 10 05",-1,0},{0,0,0}};
SV vGR[]={{"F3 0F 10 41 ? C3",-1,0},{"F3 0F 10 40 ? C3",-1,0},{"F3 0F 10 81 ? ? ? ? C3",-1,0},{"8B 41 ? C3",-1,0},{"F3 0F 10 05 ? ? ? ? C3",-1,0},{0,0,0}};
SV vHV[]={{"48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8B D9",-1,0},{"48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 48 83 EC",-1,0},{"48 89 5C 24 ? 57 48 83 EC ? 48 8B D9",-1,0},{"40 53 48 83 EC ? 48 8B D9",-1,0},{0,0,0}};
SV vOG[]={{"80 79 ? 00 74 ? B0 01 C3",-1,0},{"0F B6 41 ? C3",-1,0},{"8A 41 ? C3",-1,0},{"80 79 ? 00 0F 95 C0 C3",-1,0},{0,0,0}};
SV vSP[]={{"48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 48 83 EC",-1,0},{"48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8B F1",-1,0},{"48 89 5C 24 ? 57 48 83 EC ? 48 8B F9 48 8B DA",-1,0},{"40 53 48 83 EC ? 48 8B D9",-1,0},{0,0,0}};
uintptr_t FP(uintptr_t s,size_t z,const char*p){if(!p)return 0;std::vector<uint8_t>b;std::vector<bool>m;while(*p){if(*p==' '){p++;continue;}if(*p=='?'){b.push_back(0);m.push_back(0);p+=(p[1]=='?')?2:1;continue;}b.push_back((uint8_t)strtol(p,(char**)&p,16));m.push_back(1);}if(b.empty())return 0;for(uintptr_t i=s;i<s+z-b.size();i++){bool f=1;for(size_t j=0;j<b.size()&&f;j++)if(m[j]&&*(uint8_t*)(i+j)!=b[j])f=0;if(f)return i;}return 0;}
uintptr_t FPR(uintptr_t s,size_t z,const char*p,int r){uintptr_t a=FP(s,z,p);if(!a)return 0;return a+r+4+*(int32_t*)(a+r);}
uintptr_t AF(SV*v,uintptr_t s,size_t z,int*o){for(int i=0;v[i].s;i++){uintptr_t a=FP(s,z,v[i].s);if(a){if(o)*o=v[i].fb;if(v[i].r>=0){int32_t r=*(int32_t*)(a+v[i].r);return a+v[i].r+4+r;}return a;}}return 0;}
MCVer DV(){HMODULE m=GetModuleHandleA(0);MODULEINFO mi;GetModuleInformation(GetCurrentProcess(),m,&mi,sizeof(mi));uintptr_t s=(uintptr_t)m;size_t z=mi.SizeOfImage;if(FP(s,z,GP165))return MCVer::V1_16_5;if(FP(s,z,GP214))return MCVer::V1_21_4;return MCVer::UNKNOWN;}
bool FA(MCVer v){const char*G=(v==MCVer::V1_16_5)?GP165:GP214,*W=(v==MCVer::V1_16_5)?GW165:GW214,*T=(v==MCVer::V1_16_5)?GT165:GT214;HMODULE m=GetModuleHandleA(0);MODULEINFO mi;GetModuleInformation(GetCurrentProcess(),m,&mi,sizeof(mi));uintptr_t s=(uintptr_t)m;size_t z=mi.SizeOfImage;gA.gp=FPR(s,z,G,3);gA.gw=FPR(s,z,W,3);gA.gt=FPR(s,z,T,4);int fl=0,fr=0;gA.gpl=AF(vPL,s,z,&fl);gA.w2s=AF(vW2,s,z,0);gA.gbr=AF(vGR,s,z,&fr);gA.hv=AF(vHV,s,z,0);gA.iog=AF(vOG,s,z,0);gA.sp=AF(vSP,s,z,0);gA.plo=fl;gA.brv=fr;return gA.gp&&gA.gw;}
namespace MC{void*GP(){return gA.gp?(void*)((uintptr_t(*)())gA.gp)():0;}void*GW(){return gA.gw?(void*)((uintptr_t(*)())gA.gw)():0;}float*GT(){if(gA.gt)return(float*)gA.gt;return 0;}bool GPos(double&x,double&y,double&z){void*p=GP();if(!p)return 0;x=*(double*)((uintptr_t)p+0x28);y=*(double*)((uintptr_t)p+0x2C);z=*(double*)((uintptr_t)p+0x30);return 1;}float GHP(){void*p=GP();if(!p)return 0;return*(float*)((uintptr_t)p+0x40);}int GAr(){void*p=GP();if(!p)return 0;int t=0;for(int i=0;i<4;i++){uintptr_t s=*(uintptr_t*)((uintptr_t)p+0x60+i*8);if(s){int d=*(int*)(s+0x20),m=*(int*)(s+0x24);if(m>0)t+=(d*100)/m;}}return t/4;}void GAng(float&y,float&p){void*pl=GP();if(!pl)return;y=*(float*)((uintptr_t)pl+0x38);p=*(float*)((uintptr_t)pl+0x3C);}void SAng(float y,float p){void*pl=GP();if(!pl)return;*(float*)((uintptr_t)pl+0x38)=y;*(float*)((uintptr_t)pl+0x3C)=p;}bool OG(){void*pl=GP();if(!pl)return 0;return*(bool*)((uintptr_t)pl+0x1C);}void**GPL(int&c){c=0;void*w=GW();if(!w||!gA.plo)return 0;void**l=*(void***)((uintptr_t)w+gA.plo);c=*(int*)((uintptr_t)w+gA.plo+8);return l;}}
namespace ST{HMODULE gB=0;SIZE_T gS=0;std::atomic<bool>gP{0},gH{0};struct{HWND h;DWORD_PTR d0,d7;}gW{};PVOID gV=0;bool gVA=0;
#ifndef _M_ARM64
LONG CALLBACK V(PEXCEPTION_POINTERS e){if(e->ExceptionRecord->ExceptionCode==0x80000004L){if((DWORD_PTR)e->ExceptionRecord->ExceptionAddress==gW.d0){extern void GR();GR();return EXCEPTION_CONTINUE_EXECUTION;}}if(e->ExceptionRecord->ExceptionCode==0xC0000005L){DWORD_PTR*t=(DWORD_PTR*)e->ExceptionRecord->ExceptionInformation[1];if(t>=(DWORD_PTR*)gB&&t<(DWORD_PTR*)((BYTE*)gB+gS)){*t=0xCCCCCCCCCCCCCCCC;return EXCEPTION_CONTINUE_EXECUTION;}}return EXCEPTION_CONTINUE_SEARCH;}
void IV(void*t){__try{CONTEXT c={};c.ContextFlags=CONTEXT_DEBUG_REGISTERS;GetThreadContext(GetCurrentThread(),&c);gW.d0=(DWORD_PTR)t;gW.d7=(1<<0)|(0<<16)|(0<<18);c.Dr0=gW.d0;c.Dr7=gW.d7;SetThreadContext(GetCurrentThread(),&c);gV=AddVectoredExceptionHandler(1,V);gVA=1;}__except(1){gVA=0;}}
#else
LONG CALLBACK V(PEXCEPTION_POINTERS e){return EXCEPTION_CONTINUE_SEARCH;}
void IV(void*t){}
#endif
void WP(){__try{PPEB p=(PPEB)__readgsqword(0x60);if(!p||!p->Ldr)return;struct{LIST_ENTRY*h;WORD o;}l[]={{&p->Ldr->InLoadOrderModuleList,0},{&p->Ldr->InMemoryOrderModuleList,16},{&p->Ldr->InInitializationOrderModuleList,32}};for(auto&x:l){LIST_ENTRY*e=x.h->Flink;while(e!=x.h){auto*m=(LDR_DATA_TABLE_ENTRY*)((BYTE*)e-x.o);if(m->DllBase==gB){e->Blink->Flink=e->Flink;e->Flink->Blink=e->Blink;e->Flink=e;e->Blink=e;RtlSecureZeroMemory(m,sizeof(LDR_DATA_TABLE_ENTRY));break;}e=e->Flink;}}}__except(1){}}
void WS(){__try{static const char*t[]={"ImGui","MinHook","MENACE","CHEAT","HACK","Aimbot","ESP","SpeedHack","Reach","DETOUR","HOOK","DLL","INJECT","VEH","HWBP","PANIC",0};MEMORY_BASIC_INFORMATION m;BYTE*a=0;std::mt19937 r{std::random_device{}()};while(VirtualQuery(a,&m,sizeof(m))){if(m.State==MEM_COMMIT&&(m.Protect&(PAGE_READWRITE|PAGE_EXECUTE_READWRITE|PAGE_READONLY|PAGE_EXECUTE_READ))){BYTE*rg=(BYTE*)m.BaseAddress;SIZE_T sz=m.RegionSize;for(int i=0;t[i];i++){size_t ln=strlen(t[i]);if(ln>=sz)continue;for(SIZE_T o=0;o<sz-ln;o++){BOOL mt=1;for(size_t j=0;j<ln;j++){if(toupper(rg[o+j])!=toupper(t[i][j])){mt=0;break;}}if(mt){DWORD old;if(VirtualProtect(rg+o,ln,PAGE_READWRITE,&old)){for(size_t j=0;j<ln;j++)rg[o+j]=(BYTE)(r()&0xFF);VirtualProtect(rg+o,ln,old,&old);}o+=ln-1;}}}}a+=m.RegionSize;}}__except(1){}}
void PN(){gP=1;gH=1;if(gV){RemoveVectoredExceptionHandler(gV);CONTEXT c={};c.ContextFlags=CONTEXT_DEBUG_REGISTERS;c.Dr0=0;c.Dr7=0;SetThreadContext(GetCurrentThread(),&c);}WS();WP();__try{volatile int d=0;auto x=[](auto&s,volatile int*d)->void{if(*d>64)return;(*d)++;volatile BYTE b[1024];for(int i=0;i<1024;i++)b[i]=0;s(s,d);};x(x,&d);}__except(1){}Sleep(50);if(gB){VirtualFree(gB,0,MEM_RELEASE);gB=0;}ExitThread(0);}
void IN(HMODULE h){gB=h;MEMORY_BASIC_INFORMATION m;VirtualQuery(h,&m,sizeof(m));gS=m.RegionSize;WP();WS();}}
namespace CF{bool a=0;float aS=3,aF=90,aM=0.5f;bool aP=1,aMo=0,aH=1,aV=1;int aT=0;float aOX=0,aOY=0;bool r=0;float rD=4.2f;bool ac=0;int cMin=9,cMax=14;bool v=0;int vH=80,vV=100;bool tr=0;int tD=50;bool cr=0;bool e=0,eB=1,eH=1;bool n=0,tr2=0,fb=1,ch=0,cE=0,iE=0,mE=0;bool nH=0,nF=0,cW=0;bool s=0;float sM=1.3f;bool fl=0;float fS=1;bool ns=1,st=0,je=0,sp=0;bool nf=0,aTl=0,aAr=0,nP=0,nW=0,fB=0;bool xr=0,tC=0;int tV=18000;bool wC=0,wCl=1;bool o=0,oP=1,oR=1,oD=1,oA=1;bool sC=0;float sR=0,sG=0,sB=0;bool nFg=1,fC=0;float fR=1,fG=1,fB=1;bool h=1,hL=1,hC=1,hF=1,hA=1,hM=1,hT=1;float hR=0.42f,hG=0.36f,hB=0.91f,hAl=0.9f;float hBR=0.05f,hBG=0.05f,hBB=0.08f,hBA=0.75f;float hS=1;int hP=0;bool sF=1;float fvR=1,fvG=1,fvB=1,fvA=0.25f,fvT=1.5f;bool fvFl=0;float fvS=64;char fN[32]="",eN[32]="";std::vector<std::string> fr,en;}
void ATH(){ImGuiStyle&s=ImGui::GetStyle();ImVec4 a=ImVec4(CF::hR,CF::hG,CF::hB,1),ad=ImVec4(CF::hR*.7f,CF::hG*.7f,CF::hB*.7f,1),al=ImVec4(min(CF::hR*1.3f,1.f),min(CF::hG*1.3f,1.f),min(CF::hB*1.3f,1.f),1),bg=ImVec4(CF::hBR,CF::hBG,CF::hBB,CF::hBA),bl=ImVec4(CF::hBR*1.8f,CF::hBG*1.8f,CF::hBB*1.8f,1),bf=ImVec4(CF::hBR*2.5f,CF::hBG*2.5f,CF::hBB*2.5f,1);s.Colors.WindowBg=bg;s.Colors.ChildBg=bl;s.Colors.PopupBg=bg;s.Colors.Border=ImVec4(a.x*.3f,a.y*.3f,a.z*.3f,.5f);s.Colors.FrameBg=bf;s.Colors.FrameBgHovered=ImVec4(bf.x*1.3f,bf.y*1.3f,bf.z*1.3f,1);s.Colors.FrameBgActive=ImVec4(a.x*.3f,a.y*.3f,a.z*.3f,1);s.Colors.Button=a;s.Colors.ButtonHovered=al;s.Colors.ButtonActive=ad;s.Colors.CheckMark=a;s.Colors.SliderGrab=a;s.Colors.SliderGrabActive=al;s.Colors.Header=ImVec4(a.x*.25f,a.y*.25f,a.z*.25f,.4f);s.Colors.HeaderHovered=ImVec4(a.x*.4f,a.y*.4f,a.z*.4f,.6f);s.Colors.HeaderActive=ImVec4(a.x*.5f,a.y*.5f,a.z*.5f,.8f);s.Colors.Tab=bf;s.Colors.TabHovered=a;s.Colors.TabActive=a;s.Colors.Text=ImVec4(.91f,.91f,.94f,1);s.Colors.TextDisabled=ImVec4(.48f,.48f,.62f,1);s.Colors.Separator=ImVec4(a.x*.3f,a.y*.3f,a.z*.3f,.4f);s.Colors.ScrollbarGrab=ImVec4(a.x*.4f,a.y*.4f,a.z*.4f,.5f);s.Colors.TitleBg=bg;s.Colors.TitleBgActive=bl;s.Colors.ResizeGrip=a;s.WindowRounding=6;s.FrameRounding=3;s.ScrollbarRounding=3;s.GrabRounding=3;s.TabRounding=4;s.WindowBorderSize=1;s.FrameBorderSize=1;s.WindowPadding=ImVec2(12,10);s.FramePadding=ImVec2(8,4);s.ItemSpacing=ImVec2(8,5);s.Alpha=.95f;}
struct BN{const char*n;int*k;bool w;};std::vector<BN>gBinds;int gBA,gBR,gBC,gBV,gBT,gBE,gBN,gBT2,gBF,gBS,gBNS,gBF2,gBNF,gBX;
void IB(){gBinds={{&gBA,"A"},{&gBR,"R"},{&gBC,"C"},{&gBV,"V"},{&gBT,"T"},{&gBE,"E"},{&gBN,"N"},{&gBT2,"T2"},{&gBF,"F"},{&gBS,"S"},{&gBNS,"NS"},{&gBF2,"F2"},{&gBNF,"NF"},{&gBX,"X"}};}
const char*KN(int k){if(!k)return"[ ]";if(k==VK_LBUTTON)return"[L]";if(k==VK_RBUTTON)return"[R]";if(k==VK_SHIFT)return"[S]";if(k==VK_CONTROL)return"[C]";if(k==VK_SPACE)return"[Sp]";if(k>=VK_F1&&k<=VK_F12){static char b[8];snprintf(b,8,"[F%d]",k-VK_F1+1);return b;}if(k>='A'&&k<='Z'){static char b[8];snprintf(b,8,"[%c]",(char)k);return b;}return"[?]";}
void PB(BN&b){if(!b.w)return;for(int k=1;k<256;k++){if(GetAsyncKeyState(k)&0x8000){if(k==VK_ESCAPE)*b.k=0;else*b.k=k;b.w=0;return;}}}
namespace MD{float oT=1;bool tS=0;float D3(double x1,double y1,double z1,double x2,double y2,double z2){return(float)sqrt(pow(x2-x1,2)+pow(y2-y1,2)+pow(z2-z1,2));}float NA(float a){while(a>180)a-=360;while(a<-180)a+=360;return a;}float AD(float a,float b){float d=a-b;while(d>180)d-=360;while(d<-180)d+=360;return abs(d);}void CA(double sx,double sy,double sz,double dx,double dy,double dz,float&y,float&p){double xd=dx-sx,yd=dy-sy,zd=dz-sz;double d=sqrt(xd*xd+zd*zd);y=(float)(atan2(zd,xd)*57.29578)-90;p=(float)(-(atan2(yd,d)*57.29578));while(y>180)y-=360;while(y<-180)y+=360;if(p>90)p=90;if(p<-90)p=-90;}
void Aim(){if(!CF::a)return;double lx,ly,lz;if(!MC::GPos(lx,ly,lz))return;ly+=1.62;float cy,cp;MC::GAng(cy,cp);float bS=999999,ty=0,tp=0;bool f=0;int cnt=0;void**pl=MC::GPL(cnt);if(!pl||!cnt)return;for(int i=0;i<cnt;i++){void*e=pl[i];if(!e||e==MC::GP())continue;double tx=*(double*)((uintptr_t)e+0x28),ty2=*(double*)((uintptr_t)e+0x2C)+1.0,tz=*(double*)((uintptr_t)e+0x30);float ay,ap;CA(lx,ly,lz,tx+CF::aOX,ty2+CF::aOY,tz,ay,ap);float yd=AD(cy,ay),pd=abs(cp-ap),fd=(float)sqrt(yd*yd+pd*pd);if(fd>CF::aF/2)continue;float sc=CF::aT==0?fd:CF::aT==1?*(float*)((uintptr_t)e+0x40):fd;if(sc<bS){bS=sc;ty=ay;tp=ap;f=1;}}if(f){float ny=cy,np=cp;if(CF::aH){float d=NA(ty-cy);ny=cy+d*CF::aS*.02f*(1+CF::aM);}if(CF::aV){float d=tp-cp;np=cp+d*CF::aS*.02f*(1+CF::aM);}MC::SAng(ny,np);}}
void Trig(){if(!CF::tr)return;static DWORD lt=0;DWORD n=GetTickCount();if(n-lt<(DWORD)CF::tD)return;lt=n;}void Reach(){if(!CF::r||!gA.gbr)return;}void Vel(){if(!CF::v||!gA.hv)return;}void Crit(){if(!CF::cr)return;}
void AC(){if(!CF::ac)return;static DWORD lt=0;DWORD n=GetTickCount();int t=CF::cMin+(rand()%(CF::cMax-CF::cMin+1));if(n-lt>=(DWORD)(1000/t)){lt=n;}}
void Spd(){if(!CF::s){if(tS){float*tt=MC::GT();if(tt)*tt=oT;tS=0;}return;}float*tt=MC::GT();if(!tt)return;if(!tS){oT=*tt;tS=1;}*tt=CF::sM;}
void DFov(){if(!CF::sF)return;auto*d=ImGui::GetBackgroundDrawList();float sw=(float)GetSystemMetrics(0),sh=(float)GetSystemMetrics(1),cx=sw/2,cy=sh/2,r=CF::aF*(sh/180)*.5f;ImU32 c=ImGui::ColorConvertFloat4ToU32(ImVec4(CF::fvR,CF::fvG,CF::fvB,CF::fvA));d->AddCircle(ImVec2(cx,cy),r,c,(int)CF::fvS,CF::fvT);d->AddCircleFilled(ImVec2(cx,cy),2.5f,IM_COL32(255,255,255,180),8);char b[32];snprintf(b,32,"FOV: %.0f",CF::aF);d->AddText(ImVec2(cx-20,cy-r-16),IM_COL32(255,255,255,80),b);}
void DHUD(){if(!CF::h||ST::gH)return;auto*d=ImGui::GetBackgroundDrawList();float sw=(float)GetSystemMetrics(0),sh=(float)GetSystemMetrics(1),s=CF::hS;float x=10,y=10;if(CF::hP==0){x=sw-220*s;y=10;}else if(CF::hP==1){x=10;y=10;}else if(CF::hP==2){x=sw-220*s;y=sh-200*s;}else{x=10;y=sh-200*s;}float w=210*s,lh=14*s,p=4*s,cy=y+p;ImU32 bg=ImGui::ColorConvertFloat4ToU32(ImVec4(CF::hBR,CF::hBG,CF::hBB,CF::hBA)),tx=ImGui::ColorConvertFloat4ToU32(ImVec4(CF::hR,CF::hG,CF::hB,CF::hAl)),ac=ImGui::ColorConvertFloat4ToU32(ImVec4(CF::hR*.7f,CF::hG*.7f,CF::hB*.7f,1));float th=p*2;if(CF::hL)th+=lh*2;if(CF::hC)th+=lh*3;if(CF::hF)th+=lh;if(CF::hA)th+=lh;if(CF::hT)th+=lh;if(CF::hM){if(CF::a)th+=lh;if(CF::r)th+=lh;if(CF::ac)th+=lh;if(CF::s)th+=lh;if(CF::fl)th+=lh;if(CF::e)th+=lh;if(CF::xr)th+=lh;}th+=p;d->AddRectFilled(ImVec2(x,y),ImVec2(x+w,y+th),bg);d->AddRect(ImVec2(x,y),ImVec2(x+w,y+th),ac,0,0,1);cy=y+p;if(CF::hL){d->AddText(ImVec2(x+p,cy),tx,"MENACE");cy+=lh;d->AddText(ImVec2(x+p,cy),ac,"v1.0");cy+=lh;}if(CF::hC){double px,py,pz;if(MC::GPos(px,py,pz)){char b[64];snprintf(b,64,"X: %.1f",px);d->AddText(ImVec2(x+p,cy),tx,b);cy+=lh;snprintf(b,64,"Y: %.1f",py);d->AddText(ImVec2(x+p,cy),tx,b);cy+=lh;snprintf(b,64,"Z: %.1f",pz);d->AddText(ImVec2(x+p,cy),tx,b);cy+=lh;}}if(CF::hF){char b[32];snprintf(b,32,"FPS: %.0f",ImGui::GetIO().Framerate);d->AddText(ImVec2(x+p,cy),tx,b);cy+=lh;}if(CF::hA){int ar=MC::GAr();char b[32];snprintf(b,32,"Armor: %d%%",ar);ImU32 ac2=ar>50?IM_COL32(80,255,80,255):ar>25?IM_COL32(255,255,80,255):IM_COL32(255,80,80,255);d->AddText(ImVec2(x+p,cy),ac2,b);cy+=lh;}if(CF::hT){time_t n=time(0);struct tm*lt=localtime(&n);char b[32];snprintf(b,32,"%02d:%02d:%02d",lt->tm_hour,lt->tm_min,lt->tm_sec);d->AddText(ImVec2(x+p,cy),tx,b);cy+=lh;}if(CF::hM){ImU32 on=IM_COL32(80,255,80,255);if(CF::a){d->AddText(ImVec2(x+p,cy),on,"Aim");cy+=lh;}if(CF::r){d->AddText(ImVec2(x+p,cy),on,"Reach");cy+=lh;}if(CF::ac){d->AddText(ImVec2(x+p,cy),on,"AC");cy+=lh;}if(CF::s){d->AddText(ImVec2(x+p,cy),on,"Speed");cy+=lh;}if(CF::fl){d->AddText(ImVec2(x+p,cy),on,"Fly");cy+=lh;}if(CF::e){d->AddText(ImVec2(x+p,cy),on,"ESP");cy+=lh;}if(CF::xr){d->AddText(ImVec2(x+p,cy),on,"X-Ray");cy+=lh;}}}
void Tick(){Aim();Trig();Reach();Crit();AC();Spd();Vel();}void Render(){DFov();DHUD();}}
namespace GUI{ID3D11Device*dev=0;ID3D11DeviceContext*ctx=0;bool ok=0,vis=0;int tab=0;const char*tabs[]={"Combat","Visuals","Movement","Player","World","Friends","Theme","Info"};
void Init(IDXGISwapChain*sc){if(ok)return;sc->GetDevice(__uuidof(ID3D11Device),(void**)&dev);dev->GetImmediateContext(&ctx);ImGui::CreateContext();ImGui::GetIO().IniFilename=0;ImGui::GetIO().LogFilename=0;ImGui_ImplDX11_Init(dev,ctx);ImGui_ImplWin32_Init(FindWindowA("LWJGL",0));ATH();ok=1;}
bool SS(){return(GetAsyncKeyState(VK_F2)&0x8000)||(GetAsyncKeyState(VK_SNAPSHOT)&0x8000);}
void Render(){if(!ok||ST::gP)return;ImGui_ImplDX11_NewFrame();ImGui_ImplWin32_NewFrame();ImGui::NewFrame();MD::Render();if(!ST::gH&&!SS()){const char*v=gV==MCVer::V1_16_5?"1.16.5":gV==MCVer::V1_21_4?"1.21.4":"?";char b[64];snprintf(b,64,"MENACE | %s",v);ImGui::GetBackgroundDrawList()->AddText(ImVec2(8,6),IM_COL32(255,255,255,18),b);}if(vis&&!ST::gH&&!SS()){ImGui::SetNextWindowSize(ImVec2(580,420));ImGui::Begin("MENACE Client",&vis,8);ImGui::TextColored(ImVec4(CF::hR,CF::hG,CF::hB,1),"MENACE");ImGui::SameLine();ImGui::TextDisabled("v1.0");ImGui::Separator();if(ImGui::BeginTabBar("T")){for(int i=0;i<8;i++){if(ImGui::BeginTabItem(tabs[i])){tab=i;switch(i){case 0:ImGui::Checkbox("Aim Assist",&CF::a);if(CF::a){ImGui::Indent(16);ImGui::SliderFloat("Speed",&CF::aS,1,20);ImGui::SliderFloat("FOV",&CF::aF,10,360);ImGui::SliderFloat("Smooth",&CF::aM,0,1);ImGui::Checkbox("Players",&CF::aP);ImGui::SameLine();ImGui::Checkbox("Mobs",&CF::aMo);ImGui::Checkbox("Horizontal",&CF::aH);ImGui::SameLine();ImGui::Checkbox("Vertical",&CF::aV);ImGui::Unindent(16);}ImGui::Separator();ImGui::Checkbox("Reach",&CF::r);if(CF::r){ImGui::Indent(16);ImGui::SliderFloat("Distance",&CF::rD,3,6);ImGui::Unindent(16);}ImGui::Separator();ImGui::Checkbox("Auto Clicker",&CF::ac);if(CF::ac){ImGui::Indent(16);ImGui::SliderInt("Min CPS",&CF::cMin,1,20);ImGui::SliderInt("Max CPS",&CF::cMax,1,20);ImGui::Unindent(16);}ImGui::Separator();ImGui::Checkbox("Velocity",&CF::v);if(CF::v){ImGui::Indent(16);ImGui::SliderInt("H %",&CF::vH,0,100);ImGui::SliderInt("V %",&CF::vV,0,100);ImGui::Unindent(16);}ImGui::Separator();ImGui::Checkbox("TriggerBot",&CF::tr);ImGui::Checkbox("Criticals",&CF::cr);break;
case 1:ImGui::Checkbox("ESP",&CF::e);if(CF::e){ImGui::Indent(16);ImGui::Checkbox("Box",&CF::eB);ImGui::Checkbox("Health",&CF::eH);ImGui::Unindent(16);}ImGui::Checkbox("Nametags",&CF::n);ImGui::Checkbox("Tracers",&CF::tr2);ImGui::Checkbox("Fullbright",&CF::fb);ImGui::Checkbox("Chams",&CF::ch);ImGui::Separator();ImGui::Checkbox("Chest ESP",&CF::cE);ImGui::Checkbox("Item ESP",&CF::iE);ImGui::Checkbox("Mob ESP",&CF::mE);ImGui::Separator();ImGui::Checkbox("No HurtCam",&CF::nH);ImGui::Checkbox("No Fire",&CF::nF);ImGui::Checkbox("Clear Water",&CF::cW);ImGui::Separator();ImGui::Checkbox("Show FOV",&CF::sF);if(CF::sF){ImGui::Indent(16);ImGui::ColorEdit4("Color",&CF::fvR,5|1);ImGui::Unindent(16);}break;
case 2:ImGui::Checkbox("Speed Hack",&CF::s);if(CF::s){ImGui::Indent(16);ImGui::SliderFloat("Multiplier",&CF::sM,1,2);ImGui::Unindent(16);}ImGui::Checkbox("Fly",&CF::fl);if(CF::fl){ImGui::Indent(16);ImGui::SliderFloat("Speed",&CF::fS,0.5f,3);ImGui::Unindent(16);}ImGui::Checkbox("No Slow",&CF::ns);ImGui::Checkbox("Step",&CF::st);ImGui::Checkbox("Jesus",&CF::je);ImGui::Checkbox("Spider",&CF::sp);break;
case 3:ImGui::Checkbox("No Fall",&CF::nf);ImGui::Checkbox("Auto Tool",&CF::aTl);ImGui::Checkbox("Auto Armor",&CF::aAr);ImGui::Checkbox("No Push",&CF::nP);ImGui::Checkbox("No Web",&CF::nW);ImGui::Checkbox("Fast Bow",&CF::fB);break;
case 4:ImGui::Checkbox("X-Ray",&CF::xr);ImGui::Checkbox("Time Changer",&CF::tC);if(CF::tC){ImGui::Indent(16);ImGui::SliderInt("Time",&CF::tV,0,24000);ImGui::Unindent(16);}ImGui::Checkbox("Weather",&CF::wC);if(CF::wC){ImGui::Indent(16);ImGui::Checkbox("Clear",&CF::wCl);ImGui::Unindent(16);}ImGui::Separator();ImGui::TextColored(ImVec4(CF::hR,CF::hG,CF::hB,1),"Optimization");ImGui::Checkbox("Enabled",&CF::o);if(CF::o){ImGui::Indent(16);ImGui::Checkbox("No Particles",&CF::oP);ImGui::Checkbox("No Rain",&CF::oR);ImGui::Checkbox("No Drops",&CF::oD);ImGui::Checkbox("No Anim",&CF::oA);ImGui::Unindent(16);}ImGui::Separator();ImGui::Checkbox("Custom Sky",&CF::sC);if(CF::sC){ImGui::Indent(16);ImGui::ColorEdit3("Color",&CF::sR,5);ImGui::Unindent(16);}ImGui::Checkbox("No Fog",&CF::nFg);ImGui::Checkbox("Custom Fog",&CF::fC);if(CF::fC){ImGui::Indent(16);ImGui::ColorEdit3("Color",&CF::fR,5);ImGui::Unindent(16);}break;
case 5:ImGui::TextColored(ImVec4(CF::hR,CF::hG,CF::hB,1),"Friends & Enemies");ImGui::InputText("Friend",CF::fN,32);ImGui::SameLine();if(ImGui::Button("Add")&&strlen(CF::fN)>0){CF::fr.push_back(CF::fN);memset(CF::fN,0,32);}ImGui::InputText("Enemy",CF::eN,32);ImGui::SameLine();if(ImGui::Button("Add##2")&&strlen(CF::eN)>0){CF::en.push_back(CF::eN);memset(CF::eN,0,32);}ImGui::Separator();if(ImGui::BeginChild("L",ImVec2(0,150),1)){ImGui::Text("Friends:");for(auto&x:CF::fr)ImGui::BulletText("%s",x.c_str());ImGui::Separator();ImGui::Text("Enemies:");for(auto&x:CF::en)ImGui::BulletText("%s",x.c_str());}ImGui::EndChild();break;
case 6:ImGui::TextColored(ImVec4(CF::hR,CF::hG,CF::hB,1),"Theme & HUD");ImGui::Text("Presets:");if(ImGui::Button("Purple")){CF::hR=0.42f;CF::hG=0.36f;CF::hB=0.91f;CF::hBR=0.05f;CF::hBG=0.05f;CF::hBB=0.08f;ATH();}ImGui::SameLine();if(ImGui::Button("Blue")){CF::hR=0.18f;CF::hG=0.55f;CF::hB=0.91f;CF::hBR=0.04f;CF::hBG=0.06f;CF::hBB=0.10f;ATH();}ImGui::SameLine();if(ImGui::Button("Red")){CF::hR=0.91f;CF::hG=0.18f;CF::hB=0.24f;CF::hBR=0.08f;CF::hBG=0.04f;CF::hBB=0.05f;ATH();}ImGui::SameLine();if(ImGui::Button("Green")){CF::hR=0.18f;CF::hG=0.80f;CF::hB=0.44f;CF::hBR=0.04f;CF::hBG=0.08f;CF::hBB=0.05f;ATH();}ImGui::ColorEdit4("Accent",&CF::hR,5|1);ImGui::ColorEdit4("Background",&CF::hBR,5|1);if(ImGui::Button("Apply",ImVec2(200,28)))ATH();ImGui::Separator();ImGui::Checkbox("Enable HUD",&CF::h);if(CF::h){ImGui::Indent(16);ImGui::Checkbox("Logo",&CF::hL);ImGui::Checkbox("Coords",&CF::hC);ImGui::Checkbox("FPS",&CF::hF);ImGui::Checkbox("Armor",&CF::hA);ImGui::Checkbox("Modules",&CF::hM);ImGui::Checkbox("Time",&CF::hT);ImGui::SliderFloat("Size",&CF::hS,0.5f,2);ImGui::Combo("Pos",&CF::hP,"Right Top\0Left Top\0Right Bottom\0Left Bottom\0");ImGui::Unindent(16);}break;
case 7:ImGui::TextColored(ImVec4(CF::hR,CF::hG,CF::hB,1),"MENACE Client");ImGui::Text("MC: 1.16.5 / 1.21.4");ImGui::Text("OS: Win 7/8/10/11");ImGui::Separator();ImGui::Text("Stealth: VEH + PEB Wipe");ImGui::Separator();ImGui::PushStyleColor(0,ImVec4(0.9f,0.1f,0.1f,1));if(ImGui::Button("PANIC [END]",ImVec2(200,32)))ST::PN();ImGui::PopStyleColor();break;}ImGui::EndTabItem();}}ImGui::EndTabBar();}ImGui::End();}ImGui::Render();ImGui_ImplDX11_RenderDrawData(0);}}
void GR(){GUI::Render();}
DWORD WINAPI MT(LPVOID p){HMODULE m=(HMODULE)p;ST::IN(m);IB();while(!FindWindowA("LWJGL",0))Sleep(100);Sleep(5000);gV=DV();if(!FA(gV)){MessageBoxA(0,"Signatures not found!","MENACE",0x10);return 1;}HWND w=FindWindowA("LWJGL",0);IDXGISwapChain*sc=0;ID3D11Device*d=0;ID3D11DeviceContext*c=0;DXGI_SWAP_CHAIN_DESC desc={};desc.BufferCount=2;desc.OutputWindow=w;desc.Windowed=1;desc.SwapEffect=DXGI_SWAP_EFFECT_DISCARD;desc.BufferDesc.Format=DXGI_FORMAT_R8G8B8A8_UNORM;desc.SampleDesc.Count=1;HRESULT hr=D3D11CreateDeviceAndSwapChain(0,D3D_DRIVER_TYPE_HARDWARE,0,0,0,0,D3D11_SDK_VERSION,&desc,&sc,&d,0,&c);if(FAILED(hr))hr=D3D11CreateDeviceAndSwapChain(0,D3D_DRIVER_TYPE_WARP,0,0,0,0,D3D11_SDK_VERSION,&desc,&sc,&d,0,&c);if(SUCCEEDED(hr)){void**vt=*(void***)sc;void*pr=vt[8];ST::IV(pr);GUI::Init(sc);sc->Release();d->Release();c->Release();}while(!ST::gP){if(GetAsyncKeyState(VK_END)&0x8000){ST::PN();break;}static bool hw=0,mw=0;bool h=GetAsyncKeyState(VK_HOME)&0x8000,m=GetAsyncKeyState(VK_RSHIFT)&0x8000;if(h&&!hw)ST::gH=!ST::gH;if(m&&!mw)GUI::vis=!GUI::vis;hw=h;mw=m;MD::Tick();Sleep(8);}return 0;}
BOOL APIENTRY DllMain(HMODULE h,DWORD r,LPVOID){if(r==DLL_PROCESS_ATTACH){DisableThreadLibraryCalls(h);ST::gB=h;ST::WP();HANDLE t=CreateThread(0,0,MT,h,0,0);if(t)CloseHandle(t);}return 1;}
