use glfw::{Glfw, FAIL_ON_ERRORS};
use snafu::ResultExt;

use crate::error::GlfwInitSnafu;
use crate::Result;

pub struct App {
    pub(crate) glfw: Glfw,
}

impl App {
    pub fn new() -> Result<Self> {
        let glfw = glfw::init(FAIL_ON_ERRORS).context(GlfwInitSnafu)?;
        Ok(Self { glfw })
    }
}
