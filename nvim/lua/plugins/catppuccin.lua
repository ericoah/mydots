-- Colorscheme: Catppuccin
-- https://github.com/catppuccin/nvim
return { "catppuccin/nvim", 
	lazy = false,
	name = "catppuccin", 
	priority = 1000,
	config = function()
--[[ Configure Catppuccin ]]--
-- There is no need to call setup if you don't want to change the default options and settings.settings
		require("catppuccin").setup({
			transparent_background = true
		})
-- setup must be called before loading
		vim.cmd.colorscheme "catppuccin"
end
}
