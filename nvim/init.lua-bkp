--[[
====================================================================
==================== NEOVIM INIT FILE ==============================
====================================================================
-- Based in Kickstart and Typecraft
-- https://github.com/nvim-lua/kickstart.nvim/blob/master/init.lua
-- https://github.com/cpow/neovim-for-newbs/blob/main/init.lua
--]]

--[[
=====================================================================
=                    FIRST THINGS FIRST                             =
=====================================================================
--]]

-- Set <space> as the leader key
-- See `:help mapleader`
--  NOTE: Must happen before plugins are loaded (otherwise wrong leader will be used)
vim.g.mapleader = " "
vim.g.maplocalleader = " "

-- Set to true if you have a Nerd Font installed and selected in the terminal
vim.g.have_nerd_font = true

--[[
=====================================================================
=                    CONFIGURE VIM                                  =
=====================================================================
-]]

require("vim-options")

--[[
=====================================================================
=                    PLUGIN MANAGER                                 =
=====================================================================
--- Install `lazy.nvim` plugin manager
--  See `:help lazy.nvim.txt` or https://github.com/folke/lazy.nvim for more info
--  To check the current status of your plugins, run
--    :Lazy
--
--  You can press `?` in this menu for help. Use `:q` to close the window
--
--  To update plugins you can run
--    :Lazy update
-]]

local lazypath = vim.fn.stdpath 'data' .. '/lazy/lazy.nvim'
if not vim.loop.fs_stat(lazypath) then
  local lazyrepo = 'https://github.com/folke/lazy.nvim.git'
  vim.fn.system { 
	  'git', 
	  'clone', 
	  '--filter=blob:none', 
	  '--branch=stable', -- latest stable release
	  lazyrepo, 
	  lazypath 
  }
end 
vim.opt.rtp:prepend(lazypath)

--[[
=====================================================================
=                    INSTALL AND CONFIGURE PLUGINS                  =
=====================================================================
-]]

local opts = {}

require("lazy").setup("plugins")

