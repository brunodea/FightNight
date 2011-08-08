FONT_SIZE_DEFAULT = 18
FONT_DEFAULT = "../resources/fonts/arial.ttf" 

function MenuOpt(self)
    if not self.text then
        self.text = "No Text"
    end

    if not self.font then
        self.font = FONT_DEFAULT
    end

    if not self.fontsize then
        self.fontsize = FONT_SIZE_DEFAULT
    elseif self.fontsize <= 0 then
        ReportError("Invalid font size value.")
    end    
    
    return self
end

title_screen = {
    size = 4,
    MenuOpt{
        text = "Play",
        font = "../resources/fonts/arial.ttf",
        fontsize = 12
    },
    MenuOpt{
        text = "Multiplayer",
        font = "../resources/fonts/arial.ttf",
        fontsize = 24
    },
    MenuOpt{
        text = "Options",
        font = "../resources/fonts/arial.ttf",
        fontsize = 24
    },
    MenuOpt{
        text = "Exit",
        font = "../resources/fonts/arial.ttf",
        fontsize = 24
    }
}

