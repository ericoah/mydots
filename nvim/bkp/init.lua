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
=                    SETTING OPTIONS                                =
=====================================================================
-- See `:help vim.opt`
-- NOTE: You can change these options as you wish!
-- For more options, you can see `:help option-list`
--]]

-- Make line numbers default
vim.opt.number = true

-- You can also add relative line numbers, to help with jumping.
vim.opt.relativenumber = true

-- Enable mouse mode, can be useful for resizing splits for example!
vim.opt.mouse = 'a'

-- Don't show the mode, since it's already in the status line
vim.opt.showmode = false

-- Sync clipboard between OS and Neovim.
--  Remove this option if you want your OS clipboard to remain independent.
--  See `:help 'clipboard'`
vim.opt.clipboard = 'unnamedplus'

-- Enable break indent
vim.opt.breakindent = true

-- Save undo history
vim.opt.undofile = true
vim.opt.undodir = vim.fn.expand('~/.config/nvim/undodir')

-- Case-insensitive searching UNLESS \C or one or more capital letters in the search term
vim.opt.ignorecase = true
vim.opt.smartcase = true

-- Keep signcolumn on by default
vim.opt.signcolumn = 'yes'

-- Decrease update time
vim.opt.updatetime = 250

-- Decrease mapped sequence wait time
-- Displays which-key popup sooner
vim.opt.timeoutlen = 300

-- Configure how new splits should be opened
vim.opt.splitright = true
vim.opt.splitbelow = true

-- Sets how neovim will display certain whitespace characters in the editor.
--  See `:help 'list'`
--  and `:help 'listchars'`
vim.opt.list = true
vim.opt.listchars = { tab = '» ', trail = '·', nbsp = '␣' }

-- Preview substitutions live, as you type!
vim.opt.inccommand = 'split'

-- Show which line your cursor is on
vim.opt.cursorline = true

-- Minimal number of screen lines to keep above and below the cursor.
vim.opt.scrolloff = 10

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

--[[ Install ]]--

local plugins = {
-- Colorscheme: Catppuccin
-- https://github.com/catppuccin/nvim
{ "catppuccin/nvim", name = "catppuccin", priority = 1000 },

-- Telescope
-- https://github.com/nvim-telescope/telescope.nvim
{ 'nvim-telescope/telescope.nvim',
	tag = '0.1.6',
	dependencies = { 'nvim-lua/plenary.nvim' }
},

-- Treesitter
-- https://github.com/nvim-treesitter/nvim-treesitter/wiki/Installation
{"nvim-treesitter/nvim-treesitter", build = ":TSUpdate"},

-- Neo-tree
-- https://github.com/nvim-neo-tree/neo-tree.nvim
{"nvim-neo-tree/neo-tree.nvim",
    branch = "v3.x",
    dependencies = {
      "nvim-lua/plenary.nvim",
      "nvim-tree/nvim-web-devicons", -- not strictly required, but recommended
      "MunifTanjim/nui.nvim",
    }
},

-- Lualine
-- https://github.com/nvim-lualine/lualine.nvim
{'nvim-lualine/lualine.nvim',
    dependencies = { 'nvim-tree/nvim-web-devicons' }
}

} -- close plugins

--[[ Configure ]]--

local opts = {}

require("lazy").setup(plugins, opts)

--[[ Configure Catppuccin ]]--
-- There is no need to call setup if you don't want to change the default options and settings.settings
require("catppuccin").setup({
	transparent_background = true
})
-- setup must be called before loading
vim.cmd.colorscheme "catppuccin"

--[[ Configure Telescope ]]--

local builtin = require('telescope.builtin')
vim.keymap.set('n', '<C-p>', builtin.find_files, {})
vim.keymap.set('n', '<leader>fg', builtin.live_grep, {})
vim.keymap.set('n', '<leader>fb', builtin.buffers, {})
vim.keymap.set('n', '<leader>fh', builtin.help_tags, {})

--[[ Configure Treesitter ]]--

local config = require("nvim-treesitter.configs")
config.setup({
	ensure_installed = { "c", "lua", "python", "html", "markdown" },
          sync_install = false,
          highlight = { enable = true },
          indent = { enable = true },
        })

--[[ Configure Neotree  ]]--

vim.keymap.set('n', '<C-n>', ':Neotree<CR>')


--[[ Configure Lualine  ]]--
-- See themes in https://github.com/nvim-lualine/lualine.nvim/blob/master/THEMES.md
require('lualine').setup({
	options = { 
	 theme = 'dracula'
	}
})
