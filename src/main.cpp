#include <iostream>
#include <string>
#include <CLI/CLI.hpp>
#include <fmt/core.h>
#include <nlohmann/json.hpp>

int main(int argc, char **argv) {
    CLI::App app{"TaskFlow CLI — Console Kanban tracker with sprint analytics"};
    app.require_subcommand(1);

    // Подкоманда 'add'
    auto add_cmd = app.add_subcommand("add", "Add a new task to the backlog");
    std::string title;
    std::string priority = "Medium";
    add_cmd->add_option("-t,--title", title, "Title of the task")->required();
    add_cmd->add_option("-p,--priority", priority, "Priority (High, Medium, Low)");

    // Подкоманда 'list'
    auto list_cmd = app.add_subcommand("list", "List all tasks");
    bool all = false;
    list_cmd->add_flag("-a,--all", all, "Show all tasks, including completed");

    // Подкоманда 'report'
    auto report_cmd = app.add_subcommand("report", "Generate current sprint report (Velocity, Burndown)");
    std::string format = "text";
    report_cmd->add_option("-f,--format", format, "Format of the report (text, html, csv, json)");

    CLI11_PARSE(app, argc, argv);

    // Маршрутизация команд
    if (app.got_subcommand(add_cmd)) {
        fmt::print("✅ Task added: '{}' [Priority: {}]\n", title, priority);
        // TODO: Имплементация добавления задачи
    } 
    else if (app.got_subcommand(list_cmd)) {
        fmt::print("📋 Listing tasks...\n");
        // TODO: Имплементация вывода списка
    } 
    else if (app.got_subcommand(report_cmd)) {
        fmt::print("📊 Generating sprint report in '{}' format...\n", format);
        // TODO: Имплементация аналитики
    }

    return 0;
}
