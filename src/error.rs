use snafu::Snafu;

#[derive(Debug, Snafu)]
#[snafu(visibility(pub))]
pub enum Error {
    #[snafu(display("Failed to initialize GLFW"))]
    GlfwInitError { source: glfw::InitError },

    #[snafu(display("Unable to create window"))]
    UnableToCreateWindow {},
}
