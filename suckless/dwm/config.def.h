/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int refresh_rate    = 75;     /* matches dwm's mouse event processing to your monitor's refresh rate for smoother window interactions */
static const unsigned int enable_noborder = 1;      /* toggles noborder feature (0=disabled, 1=enabled) */
static const unsigned int borderpx        = 2;      /* border pixel of windows */
static const unsigned int gappx		  = 10;      /* border pixel of windows */
static const unsigned int snap            = 32;     /* snap pixel */
static const int swallowfloating          = 1;      /* 1 means swallow floating windows by default */
static const unsigned int systraypinning  = 0;      /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft   = 0;      /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing  = 4;      /* systray spacing */
static const int systraypinningfailfirst  = 1;      /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray              = 1;      /* 0 means no systray */
static const int showbar                  = 1;      /* 0 means no bar */
static const int topbar                   = 1;      /* 0 means bottom bar */
static const char *fonts[]                = { "Roboto Nerd Font size=14", "awesome:pixelsize=18:antialias=true:autohint=true"};
// inactive window border color 
static const char normbordercolor[]       = "#3B4252";
// background color
static const char normbgcolor[]           = "#2E3440";
// font color
static const char normfgcolor[]           = "#D8DEE9";
// active border color
static const char selbordercolor[]        = "#434C5E";
// bar second color 
static const char selbgcolor[]            = "#434C5E";
// current tag and window font color
static const char selfgcolor[]            = "#ECEFF4";

static const char *colors[][3]      = {
	/*               fg           bg           border   */
	[SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
	[SchemeSel] =  { selfgcolor,  selbgcolor,  selbordercolor },
};

static const char *const autostart[] = {
  "xset", "s", "off", NULL,
  "xset", "s", "noblank", NULL,
  "xset", "-dpms", NULL,
  //"export PATH=$PATH:$HOME/.nix-profile/bin/", NULL,
  "dbus-update-activation-environment", "--systemd", "--all", NULL,
  "/usr/lib/mate-polkit/polkit-mate-authentication-agent-1", NULL,
  "dunst", NULL,
  "flameshot", NULL,
  "blueman-applet", NULL,	
  "pasystray", NULL,	
  "sh", "-c", "nitrogen --restore", NULL,
  "sh", "-c", "setxkbmap -layout us -variant intl", NULL,
  "sh", "-c", "compton --backend glx --vsync opengl-swc", NULL,
  "LANG=pt_BR.UTF-8", NULL,
//  "slstatus", NULL,
  "dwmblocks", NULL,
NULL /* terminate */
};

/* tagging */
static const char *tags[] = {"", "", "", "", "" };

static const char ptagf[] = "[%s %s]";  /* format of a tag label */
static const char etagf[] = "[%s]";     /* format of an empty tag */
static const int lcaselbl = 0;          /* 1 means make tag label lowercase */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class     instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
	{ "St",		NULL,     NULL,           0,         0,          1,           0,        -1 },
	{ "alacritty",	NULL,     NULL,           0,         0,          1,           0,        -1 },
	{ NULL,		NULL,     "Event Tester", 0,         0,          0,           1,        -1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "",      tile },    /* first entry is default */
	{ "",      NULL },    /* no layout function means floating behavior */
	{ "",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define STATUSBAR "dwmblocks"
/* Definir o path */
#define PATH "/home/erico/.local/state/nix/profile/bin/"

/* commands */
static const char *launchercmd[] = { "rofi", "-show", "drun", "-theme", "~/.config/rofi/launchers/type-2/style-6.rasi", NULL };
static const char *browsercmd[] = { PATH "brave", NULL };
static const char *termcmd[]  = { "alacritty", NULL };

static Key keys[] = {
	/* modifier                     key            function                argument */
	{ MODKEY,                       XK_r,          spawn,                  {.v = launchercmd} },
	{ MODKEY,                       XK_Return,     spawn,                  {.v = termcmd } },
	{ MODKEY,                       XK_b,	       spawn,                  {.v = browsercmd } },
	{ MODKEY|Mod1Mask,              XK_b,          spawn,                  SHCMD ("flatpak run com.google.Chrome")},
	{ MODKEY,                       XK_z,          spawn,                  SHCMD ("feh --bg-fill --randomize ~/Imagens/backgrounds/")},
	{ MODKEY,                       XK_p,          spawn,                  SHCMD ("flameshot full -p ~/Imagens/Capturas/")},
	{ MODKEY|ShiftMask,             XK_p,          spawn,                  SHCMD ("flameshot gui -p ~/Imagens/Capturas/")},
	{ MODKEY|ControlMask,           XK_p,          spawn,                  SHCMD ("flameshot gui --clipboard")},
	{ MODKEY,                       XK_e,          spawn,                  SHCMD ("thunar")},
	{ MODKEY,                       XK_v,          spawn,                  SHCMD ("pavucontrol")},
	{ MODKEY,                       XK_o,          spawn,                  SHCMD ("obsidian")},
	{ 0,                            0x1008ff02,    spawn,                  SHCMD ("xbacklight -inc 10")},
	{ 0,                            0x1008ff03,    spawn,                  SHCMD ("xbacklight -dec 10")},
	{ 0,                            0x1008ff11,    spawn,                  SHCMD ("pamixer --decrease 5 --unmute")},
	{ 0,                            0x1008ff12,    spawn,                  SHCMD ("pamixer --mute")},
	{ 0,                            0x1008ff13,    spawn,                  SHCMD ("pamixer --increase 5 --unmute")},
	{ MODKEY|ShiftMask,             XK_b,          togglebar,              {0} },
	{ MODKEY,                       XK_j,          focusstack,             {.i = +1 } },
	{ MODKEY,                       XK_k,          focusstack,             {.i = -1 } },
	{ MODKEY,                       XK_i,          incnmaster,             {.i = +1 } },
	{ MODKEY,                       XK_d,          incnmaster,             {.i = -1 } },
	{ MODKEY,                       XK_h,          setmfact,               {.f = -0.05} },
	{ MODKEY,                       XK_l,          setmfact,               {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_h,          setcfact,               {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_l,          setcfact,               {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_o,          setcfact,               {.f =  0.00} },
	{ MODKEY,                       XK_Return,     zoom,                   {0} },
	{ MODKEY,                       XK_Tab,        view,                   {0} },
	{ MODKEY,                       XK_q,          killclient,             {0} },
	{ MODKEY,                       XK_t,          setlayout,              {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,          setlayout,              {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,          fullscreen,             {0} },
	{ MODKEY,                       XK_space,      setlayout,              {0} },
	{ MODKEY|ShiftMask,             XK_m,          togglefloating,         {0} },
	{ MODKEY|ShiftMask,             XK_y,          togglefakefullscreen,   {0} },
	{ MODKEY,                       XK_0,          view,                   {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,          tag,                    {.ui = ~0 } },
	{ MODKEY,                       XK_comma,      focusmon,               {.i = -1 } },
	{ MODKEY,                       XK_period,     focusmon,               {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,      tagmon,                 {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,     tagmon,                 {.i = +1 } },
        { MODKEY,                       XK_Left,       shiftview,              {.i = -1 } },
	{ MODKEY,                       XK_Right,      shiftview,              {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_Left,       shifttag,               {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_Right,      shifttag,               {.i = +1 } },
	TAGKEYS(                        XK_1,                                  0)
	TAGKEYS(                        XK_2,                                  1)
	TAGKEYS(                        XK_3,                                  2)
	TAGKEYS(                        XK_4,                                  3)
	TAGKEYS(                        XK_5,                                  4)
	{ MODKEY|ShiftMask,             XK_q,          quit,                   {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_r,          spawn,                  SHCMD("systemctl reboot")},
	{ MODKEY|ControlMask|ShiftMask, XK_s,          spawn,                  SHCMD("systemctl suspend")},
	{ MODKEY|ControlMask|ShiftMask, XK_q,          spawn,                  SHCMD("systemctl poweroff")},
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
	{ ClkClientWin,         MODKEY,         Button1,        moveorplace,    {.i = 2} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
