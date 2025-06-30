# Enable Powerlevel10k instant prompt. Should stay close to the top of ~/.config/zsh/.zshrc.
# Initialization code that may require console input (password prompts, [y/n]
# confirmations, etc.) must go above this block; everything else may go below.
if [[ -r "${XDG_CACHE_HOME:-$HOME/.cache}/p10k-instant-prompt-${(%):-%n}.zsh" ]]; then
  source "${XDG_CACHE_HOME:-$HOME/.cache}/p10k-instant-prompt-${(%):-%n}.zsh"
fi

# Enable Powerlevel10k instant prompt. Should stay close to the top of ~/.zshrc.
# Initialization code that may require console input (password prompts, [y/n]
# confirmations, etc.) must go above this block; everything else may go below.
#if [[ -r "${XDG_CACHE_HOME:-$HOME/.cache}/p10k-instant-prompt-${(%):-%n}.zsh" ]]; then
 # source "${XDG_CACHE_HOME:-$HOME/.cache}/p10k-instant-prompt-${(%):-%n}.zsh"
#fi



# History in cache directory:
HISTSIZE=100000
SAVEHIST=100000
HISTFILE=~/.config/zsh/.zsh_history

# options
unsetopt menu_complete
unsetopt flowcontrol
setopt prompt_subst
setopt always_to_end
#setopt append_history
setopt extended_history # record command start time
setopt auto_menu
setopt complete_in_word
setopt hist_expire_dups_first
setopt hist_ignore_dups # do not put duplicated command into history list
setopt hist_ignore_space 
setopt hist_verify
setopt inc_append_history # append command to history file immediately after execution
setopt share_history

autoload -U compinit 
compinit


# If you come from bash you might have to change your $PATH.
export PATH=$HOME/bin:/usr/local/bin:$PATH

export PATH=$PATH:"$HOME/.local/bin:$HOME/.cargo/bin:/var/lib/flatpak/exports/bin:/.local/share/flatpak/exports/bin"


export PATH="$PATH:/opt/nvim-linux64/bin"

#themes
#source ~/.p10k.zsh
source ~/.config/zsh/powerlevel10k/powerlevel10k.zsh-theme

# plugins
source ~/.config/zsh/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh
source ~/.config/zsh/zsh-autosuggestions/zsh-autosuggestions.zsh
source ~/.config/zsh/git/git.plugin.zsh
source ~/.config/zsh/history/history.plugin.zsh
source ~/.config/zsh/sudo/sudo.plugin.zsh

#alias
source ~/.config/zsh/aliases.zsh

# User configuration

# You may need to manually set your language environment
export LANG=pt_BR.UTF-8

# To customize prompt, run `p10k configure` or edit ~/config/zsh/.p10k.zsh.
#[[ ! -f ~/.config/zsh/.p10k.zsh ]] || source ~/.config/zsh/.p10k.zsh


# Add directory to the $PATH variable
PATH=$PATH:~/.config/rofi/scripts


# Created by `pipx` on 2023-12-08 20:02:56
export PATH="$PATH:/home/erico/.local/bin"

eval "$(zoxide init zsh)"


export GTK_IM_MODULE="ibus"
export QT_IM_MODULE="ibus"
#XCOMPOSEFILE=$HOME/.XCompose


# GitHub Titus Additions

gcom() {
	git add .
	git commit -m "$1"
}
lazyg() {
	git add .
	git commit -m "$1"
	git push
}

# XDG DIRS
#
export CARGO_HOME="$XDG_DATA_HOME"/cargo
export CUDA_CACHE_PATH="$XDG_CACHE_HOME"/nv
export GNUPGHOME="$XDG_DATA_HOME"/gnupg
export XCURSOR_PATH=/usr/share/icons:$XDG_DATA_HOME/icons
export LESSHISTFILE="$XDG_STATE_HOME"/less/history
export ICEAUTHORITY="$XDG_CACHE_HOME"/ICEauthority
export XCOMPOSEFILE="$XDG_CONFIG_HOME"/X11/xcompose
export MPLAYER_HOME="$XDG_CONFIG_HOME"/mplayer
#nvidia-settings --config="$XDG_CONFIG_HOME"/nvidia/settings
export ZSH="$XDG_DATA_HOME"/oh-my-zsh
export ZDOTDIR="$HOME"/.config/zsh
export GNUPGHOME="$XDG_DATA_HOME"/gnupg
export GTK2_RC_FILES="$XDG_CONFIG_HOME"/gtk-2.0/gtkrc
export PYTHONSTARTUP="/etc/python/pythonrc"
export INPUTRC="$XDG_CONFIG_HOME"/readline/inputrc
export W3M_DIR="$XDG_DATA_HOME"/w3m
alias wget=wget --hsts-file="$XDG_DATA_HOME/wget-hsts"
export XINITRC="$XDG_CONFIG_HOME"/X11/xinitrc
# export XAUTHORITY="$XDG_RUNTIME_DIR"/Xauthority
export XAUTHORITY=$HOME/.Xauthority

# To customize prompt, run `p10k configure` or edit ~/.config/zsh/.p10k.zsh.
[[ ! -f ~/.config/zsh/.p10k.zsh ]] || source ~/.config/zsh/.p10k.zsh
