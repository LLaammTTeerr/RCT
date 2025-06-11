#pragma once

class MouseCommand {
public:
    virtual ~MouseCommand(void) = default;
    virtual void execute() = 0;
};

class MouseClickCommand : public MouseCommand {
public:
    void execute() override;
};