/* see license file for copyright and license details. */

/* appearance */
static const unsigned int refresh_rate    = 75;     /* matches dwm's mouse event processing to your monitor's refresh rate for smoother window interactions */
static const unsigned int enable_noborder = 1;      /* toggles noborder feature (0=disabled, 1=enabled) */
static const unsigned int borderpx        = 2;      /* border pixel of windows */
static const unsigned int gappx		  = 10;      /* border pixel of windows */
static const unsigned int snap            = 32;     /* snap pixel */
static const int swallowfloating          = 1;      /* 1 means swallow floating windows by default */
static const unsigned int systraypinning  = 0;      /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor x */
static const unsigned int systrayonleft   = 0;      /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing  = 4;      /* systray spacing */
static const int systraypinningfailfirst  = 1;      /* 1: if pinning fails, display systray on the first monitor, false: display systray on the last monitor*/
static const int showsystray              = 1;      /* 0 means no systray */
static const int showbar                  = 1;      /* 0 means no bar */
static const int topbar                   = 1;      /* 0 means bottom bar */
static const char *fonts[]                = { "roboto nerd font size=14", "awesome:pixelsize=18:antialias=true:autohint=true"};
// inactive window border color 
static const char normbordercolor[]       = "#3b4252";
// background color
static const char normbgcolor[]           = "#2e3440";
// font color
static const char normfgcolor[]           = "#d8dee9";
// active border color
static const char selbordercolor[]        = "#434c5e";
// bar second color 
static const char selbgcolor[]            = "#434c5e";
// current tag and window font color
static const char selfgcolor[]            = "#eceff4";

static const char *colors[][3]      = {
	/*               fg           bg           border   */
	[schemenorm] = { normfgcolor, normbgcolor, normbordercolor },
	[schemesel] =  { selfgcolor,  selbgcolor,  selbordercolor },
};

static const char *const autostart[] = {
  "xset", "s", "off", null,
  "xset", "s", "noblank", null,
  "xset", "-dpms", null,
  //"export path=$path:$home/.nix-profile/bin/", null,
  "dbus-update-activation-environment", "--systemd", "--all", null,
  "/usr/lib/mate-polkit/polkit-mate-authentication-agent-1", null,
  "dunst", null,
  "flameshot", null,
  "blueman-applet", null,	
  "pasystray", null,	
  "sh", "-c", "nitrogen --restore", null,
  "sh", "-c", "setxkbmap -layout us -variant intl", null,
  "sh", "-c", "compton --backend glx --vsync opengl-swc", null,
  "lang=pt_br.utf-8", null,
//  "slstatus", null,
  "dwmblocks", null,
null /* terminate */
};

/* tagging */
static const char *tags[] = { "", "", "", "", "" };

static const char ptagf[] = "[%s %s]";  /* format of a tag label */
static const char etagf[] = "[%s]";     /* format of an empty tag */
static const int lcaselbl = 0;          /* 1 means make tag label lowercase */

static const rule rules[] = {
	/* xprop(1):
	 *	wm_class(string) = instance, class
	 *	wm_name(string) = title
	 */
	/* class     instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
	{ "kitty",	null,     null,           0,         0,          1,           0,        -1 },
	{ "alacritty",	null,     null,           0,         0,          1,           0,        -1 },
	{ null,		null,     "event tester", 0,         0,          0,           1,        -1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const layout layouts[] = {
	/* symbol     arrange function */
	{ "",      tile },    /* first entry is default */
	{ "",      null },    /* no layout function means floating behavior */
	{ "",      monocle },
};

/* key definitions */
#define modkey mod4mask
#define tagkeys(key,tag) \
	{ modkey,                       key,      view,           {.ui = 1 << tag} }, \
	{ modkey|controlmask,           key,      toggleview,     {.ui = 1 << tag} }, \
	{ modkey|shiftmask,             key,      tag,            {.ui = 1 << tag} }, \
	{ modkey|controlmask|shiftmask, key,      toggletag,      {.ui = 1 << tag} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define shcmd(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, null } }
#define statusbar "dwmblocks"
/* definir o path */

/* commands */
static const char *launchercmd[] = { "rofi", "-show", "drun", "-theme", "~/.config/rofi/launchers/type-2/style-6.rasi", null };
static const char *browsercmd[] = { "brave", null };*/

static const char *termcmd[]  = { "alacritty", null };

static key keys[] = {
	/* modifier                     key            function                argument */
	{ modkey,                       xk_r,          spawn,                  {.v = launchercmd} },
	{ modkey,                       xk_return,     spawn,                  {.v = termcmd } },
	{ modkey,                       xk_b,	       spawn,                  {.v = browsercmd } },
	{ modkey,              		xk_b,          spawn,                  shcmd ("flatpak run com.brave.Browser")},
	{ modkey|mod1mask,              xk_b,          spawn,                  shcmd ("flatpak run com.google.chrome")},
	{ modkey,                       xk_z,          spawn,                  shcmd ("feh --bg-fill --randomize ~/imagens/backgrounds/")},
	{ modkey,                       xk_p,          spawn,                  shcmd ("flameshot full -p ~/imagens/capturas/")},
	{ modkey|shiftmask,             xk_p,          spawn,                  shcmd ("flameshot gui -p ~/imagens/capturas/")},
	{ modkey|controlmask,           xk_p,          spawn,                  shcmd ("flameshot gui --clipboard")},
	{ modkey,                       xk_e,          spawn,                  shcmd ("thunar")},
	{ modkey,                       xk_v,          spawn,                  shcmd ("pavucontrol")},
	{ modkey,                       xk_o,          spawn,                  shcmd ("obsidian")},
	{ 0,                            0x1008ff02,    spawn,                  shcmd ("xbacklight -inc 10")},
	{ 0,                            0x1008ff03,    spawn,                  shcmd ("xbacklight -dec 10")},
	{ 0,                            0x1008ff11,    spawn,                  shcmd ("pamixer --decrease 5 --unmute")},
	{ 0,                            0x1008ff12,    spawn,                  shcmd ("pamixer --mute")},
	{ 0,                            0x1008ff13,    spawn,                  shcmd ("pamixer --increase 5 --unmute")},
	{ modkey|shiftmask,             xk_b,          togglebar,              {0} },
	{ modkey,                       xk_j,          focusstack,             {.i = +1 } },
	{ modkey,                       xk_k,          focusstack,             {.i = -1 } },
	{ modkey,                       xk_i,          incnmaster,             {.i = +1 } },
	{ modkey,                       xk_d,          incnmaster,             {.i = -1 } },
	{ modkey,                       xk_h,          setmfact,               {.f = -0.05} },
	{ modkey,                       xk_l,          setmfact,               {.f = +0.05} },
	{ modkey|shiftmask,             xk_h,          setcfact,               {.f = +0.25} },
	{ modkey|shiftmask,             xk_l,          setcfact,               {.f = -0.25} },
	{ modkey|shiftmask,             xk_o,          setcfact,               {.f =  0.00} },
	{ modkey|shiftmask,             xk_return,     zoom,                   {0} },
	{ modkey,                       xk_tab,        view,                   {0} },
	{ modkey,                       xk_q,          killclient,             {0} },
	{ modkey,                       xk_t,          setlayout,              {.v = &layouts[0]} },
	{ modkey,                       xk_f,          setlayout,              {.v = &layouts[1]} },
	{ modkey,                       xk_m,          fullscreen,             {0} },
	{ modkey,                       xk_space,      setlayout,              {0} },
	{ modkey|shiftmask,             xk_m,          togglefloating,         {0} },
	{ modkey|shiftmask,             xk_y,          togglefakefullscreen,   {0} },
	{ modkey,                       xk_0,          view,                   {.ui = ~0 } },
	{ modkey|shiftmask,             xk_0,          tag,                    {.ui = ~0 } },
	{ modkey,                       xk_comma,      focusmon,               {.i = -1 } },
	{ modkey,                       xk_period,     focusmon,               {.i = +1 } },
	{ modkey|shiftmask,             xk_comma,      tagmon,                 {.i = -1 } },
	{ modkey|shiftmask,             xk_period,     tagmon,                 {.i = +1 } },
        { modkey|controlmask,           xk_left,       shiftview,              {.i = -1 } },
	{ modkey|controlmask,           xk_right,      shiftview,              {.i = +1 } },
	{ modkey|shiftmask,             xk_left,       shifttag,               {.i = -1 } },
	{ modkey|shiftmask,             xk_right,      shifttag,               {.i = +1 } },
	tagkeys(                        xk_1,                                  0)
	tagkeys(                        xk_2,                                  1)
	tagkeys(                        xk_3,                                  2)
	tagkeys(                        xk_4,                                  3)
	tagkeys(                        xk_5,                                  4)
	{ modkey|shiftmask,             xk_q,          quit,                   {0} },
	{ modkey|controlmask|shiftmask, xk_r,          spawn,                  shcmd("systemctl reboot")},
	{ modkey|controlmask|shiftmask, xk_s,          spawn,                  shcmd("systemctl suspend")},
	{ modkey|controlmask|shiftmask, xk_q,          spawn,                  shcmd("systemctl poweroff")},
};

/* button definitions */
/* click can be clktagbar, clkltsymbol, clkstatustext, clkwintitle, clkclientwin, or clkrootwin */
static button buttons[] = {
	/* click                event mask      button          function        argument */
	{ clktagbar,            modkey,         button1,        tag,            {0} },
	{ clktagbar,            modkey,         button3,        toggletag,      {0} },
	{ clkwintitle,          0,              button2,        zoom,           {0} },
	{ clkstatustext,        0,              button1,        sigstatusbar,   {.i = 1} },
	{ clkstatustext,        0,              button2,        sigstatusbar,   {.i = 2} },
	{ clkstatustext,        0,              button3,        sigstatusbar,   {.i = 3} },
	{ clkclientwin,         modkey,         button1,        moveorplace,    {.i = 2} },
	{ clkclientwin,         modkey,         button2,        togglefloating, {0} },
	{ clkclientwin,         modkey,         button3,        resizemouse,    {0} },
	{ clktagbar,            0,              button1,        view,           {0} },
	{ clktagbar,            0,              button3,        toggleview,     {0} },
	{ clktagbar,            modkey,         button1,        tag,            {0} },
	{ clktagbar,            modkey,         button3,        toggletag,      {0} },
};
