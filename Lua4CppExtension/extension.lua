function Activate(context)
    context.name = "Wigfrid"
    context.health = 100
    context.x = 0.1
    context.y = -0.7
    context.death = false
    context:print()
    return 0
end

function Deactivate(context)
    context.death = true
end

function MoveX(context)
    context.x = context.x + context.x_delta
end

function MoveY(context)
    context.y = context.y + context.y_delta
end

function Attacked(context)
    context.health = context.health - context.damage
    context:print()
    return 0
end
