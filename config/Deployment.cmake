# Task files could be using headers in tasks/ so add the relevant directory in
# our include path
include_directories(${CMAKE_SOURCE_DIR}/<%= Generation::AUTOMATIC_AREA_NAME %>/<%= component.name %>)
include_directories(${CMAKE_SOURCE_DIR}/<%= Generation::AUTOMATIC_AREA_NAME %>)

<% dependencies = deployer.dependencies %>
<%= Generation.cmake_pkgconfig_require(dependencies) %>

add_executable(<%= deployer.name %> ${CMAKE_SOURCE_DIR}/<%= Generation::AUTOMATIC_AREA_NAME %>/main-<%= deployer.name %>.cpp)
<% if component.typekit %>
target_link_libraries(<%= deployer.name %> <%= component.name %>-typekit-${OROCOS_TARGET})
<% deployer.transports.each do |transport_name| %>
target_link_libraries(<%= deployer.name %> <%= component.name %>-transport-<%= transport_name %>-${OROCOS_TARGET})
<% end %>
<% end %>
list(APPEND CMAKE_PREFIX_PATH ${OrocosRTT_PREFIX})
find_package(RTTPlugin COMPONENTS rtt-typekit <%= deployer.rtt_transports.map { |transport_name| "rtt-transport-#{transport_name}" }.join(" ") %>)
target_link_libraries(<%= deployer.name %> ${RTT_PLUGIN_rtt-typekit_LIBRARY})
<% deployer.rtt_transports.each do |transport_name| %>
target_link_libraries(<%= deployer.name %> ${RTT_PLUGIN_rtt-transport-<%= transport_name %>_LIBRARY})
<% end %>
<% if !component.self_tasks.empty? %>
target_link_libraries(<%= deployer.name %> <%= component.name %>-tasks-${OROCOS_TARGET})
<% end %>
<%= Generation.cmake_pkgconfig_link_noncorba(deployer.name, dependencies) %>
<%= if deployer.corba_enabled?
        Generation.cmake_pkgconfig_link_corba(deployer.name, dependencies)
    end %>

<% if deployer.install? %>
install(TARGETS <%= deployer.name %>
    RUNTIME DESTINATION bin)
<% end %>

add_dependencies(<%= deployer.name %>
    check-uptodate)

configure_file(<%= Generation::AUTOMATIC_AREA_NAME %>/<%= deployer.name %>.pc.in
    orogen-<%= deployer.name %>.pc @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/orogen-<%= deployer.name %>.pc
    DESTINATION lib/pkgconfig)

