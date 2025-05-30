-- Telescope
-- https://github.com/nvim-telescope/telescope.nvim
 return { 
	'nvim-telescope/telescope.nvim',
	tag = '0.1.6',
	dependencies = { 'nvim-lua/plenary.nvim' },
	config = function()
--[[ Configure Telescope ]]--
		local builtin = require('telescope.builtin')
		vim.keymap.set('n', '<C-p>', builtin.find_files, {})
		vim.keymap.set('n', '<leader>fg', builtin.live_grep, {})
		vim.keymap.set('n', '<leader>fb', builtin.buffers, {})
		vim.keymap.set('n', '<leader>fh', builtin.help_tags, {})
	end
}

